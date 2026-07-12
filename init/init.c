#include "syscall.h"
#include "string.h"
#include "print.h"
#include "input.h"
#include "string_compare.h"
#include "strchr.h"
#include "parser.h"


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

    char *command;
    char *argument;

    parse(buffer, &command, &argument);

    char *space = strchr(buffer, ' ');

    if (strcmp(command,"help") == 0)
    {
        print("Available commands\n"
            "help\n"
            "echo\n"
            "clear\n"
            "exit\n");
    }
    else if (strcmp(command,"echo")==0)
    {
        if(argument){
            print(argument);
            print("\n");
        }
    }

    else if (strcmp(command,"clear")==0)
    {
    
        print("\033[2J\033[H");
        print("\n");
    }

    else
    {
        print("Unknown command\n");
    }
}
}