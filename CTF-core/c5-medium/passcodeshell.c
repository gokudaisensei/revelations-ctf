#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void secret_shell()
{
    printf("You found the secret function! Accessing the protected directory...\n");
    // Change directory to the protected directory
    if (chdir("/protected") != 0)
    {
        perror("chdir failed");
        exit(1);
    }
    // Spawn a shell. Now the user will be in /protected.
    system("/bin/sh");
}

void vulnerable_function()
{
    char buffer[64];

    printf("Enter your passcode: ");
    gets(buffer); // Vulnerable function: No bounds checking!

    printf("Access Denied! Try again.\n");
}

int main()
{
    printf("Welcome to the Passcode Shell!\n");
    vulnerable_function();
    return 0;
}
