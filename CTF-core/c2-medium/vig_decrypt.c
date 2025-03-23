#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to decrypt ciphertext using Vigenère cipher
void decrypt(const char *key, const char *ciphertext, char *plaintext)
{
    int key_len = strlen(key);
    int text_len = strlen(ciphertext);
    int key_index = 0;
    for (int i = 0; i < text_len; i++)
    {
        char c = ciphertext[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            // Normalize the key letter to uppercase and calculate its shift
            char k = toupper(key[key_index % key_len]);
            int shift = k - 'A';
            // Decrypt: subtract the key shift, wrap around using mod 26
            plaintext[i] = (char)(((c - base) - shift + 26) % 26 + base);
            key_index++;
        }
        else
        {
            // Non-alphabetic characters remain unchanged
            plaintext[i] = c;
        }
    }
    plaintext[text_len] = '\0';
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <keyword> <ciphertext>\n", argv[0]);
        return 1;
    }

    const char *keyword = argv[1];
    const char *ciphertext = argv[2];

    // Allocate memory for the plaintext
    char *plaintext = malloc(strlen(ciphertext) + 1);
    if (!plaintext)
    {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }

    // Decrypt the ciphertext using the provided keyword
    decrypt(keyword, ciphertext, plaintext);
    printf("Decrypted text: %s\n", plaintext);

    free(plaintext);
    return 0;
}
