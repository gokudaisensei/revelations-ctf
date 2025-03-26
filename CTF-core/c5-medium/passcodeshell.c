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

    // Force the process to run as root
    if (setgid(0) != 0)
    {
        perror("setgid failed");
        exit(1);
    }
    if (setuid(0) != 0)
    {
        perror("setuid failed");
        exit(1);
    }

    // Spawn a shell using execve(); the shell will be running as root.
    char *args[] = {"/bin/sh", NULL};
    char *envp[] = {NULL};
    execve("/bin/sh", args, envp);

    // If execve returns, an error occurred.
    perror("execve failed");
    exit(1);
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
