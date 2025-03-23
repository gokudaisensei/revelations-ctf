#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[64];
    // Hidden password (flag) embedded in the binary.
    char password[] = "FLAG{TRAP_CRACKED}";

    // Noise strings to obfuscate the binary
    char noise1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    char noise2[] = "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    char noise3[] = "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.";

    printf("Enter password to disable Tom's trap: ");
    fgets(input, sizeof(input), stdin);
    // Remove newline if present.
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, password) == 0)
    {
        printf("Trap disabled! Secret flag is: %s\n", password);
    }
    else
    {
        printf("Access Denied!\n");
    }
    return 0;
}
