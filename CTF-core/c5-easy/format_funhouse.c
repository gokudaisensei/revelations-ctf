#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input[256];

    // Some distracting strings to obfuscate the binary.
    char noise1[] = "Cheddar, Gouda, and Swiss are all delicious.";
    char noise2[] = "Tom's traps are not as secure as he thinks.";
    char noise3[] = "Beware of Jerry's mischief and the hidden clues.";

    char flag[] = "FLAG{CHEESE_CATALOG_COMPROMISED}";

    // Vulnerable printing: using input as format string directly.
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);
    // Vulnerability: user-controlled format string.
    printf(input);

    return 0;
}
