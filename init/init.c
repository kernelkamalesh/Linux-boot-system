#include "syscall.h"
#include "string.h"
#include "print.h"
#include "input.h"
#include "string_compare.h"


void kmain(void)
{
char buffer[128];

while (1)
{
    char buffer[128];

    print("mysh> ");

    long n = input(buffer, sizeof(buffer) - 1);

    if (n > 0 && buffer[n - 1] == '\n')
        n--;

    buffer[n] = '\0';

    if (strcmp(buffer, "help") == 0)
    {
        print("Available commands\n"
            "help\n"
            "echo\n"
            "clear\n"
            "exit\n");
    }
    else
    {
        print("Unknown command\n");
    }
}
}
