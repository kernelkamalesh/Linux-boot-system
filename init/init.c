#include "syscall.h"
#include "string.h"
#include "print.h"
#include "input.h"
#include "string_compare.h"
#include "strchr.h"


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

    char *space = strchr(buffer, ' ');

    if (strcmp(buffer, "help") == 0)
    {
        print("Available commands\n"
            "help\n"
            "echo\n"
            "clear\n"
            "exit\n");
    }
    else if (buffer[0] == 'e' &&
         buffer[1] == 'c' &&
         buffer[2] == 'h' &&
         buffer[3] == 'o' &&
         buffer[4] == ' ')
    {
    print(space + 1);
    print("\n");
    }
    else
    {
        print("Unknown command\n");
    }
}
}
