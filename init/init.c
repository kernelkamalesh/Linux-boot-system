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
    char cwd[256];

    parse(buffer, &command, &argument);

    char *space = strchr(buffer, ' ');

    if (strcmp(command,"help") == 0)
    {
        print("Available commands\n"
            "help\n"
            "echo\n"
            "clear\n"
            "exit\n"
            "pwd\n");
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

    else if (strcmp(command, "exit") == 0)
    {
        print("we can't actually exit because we are inside a qemu but can exit the mysh(PID 1)\n");
        print("exiting...");
        exit(0);
    }

    else if (strcmp(command, "pwd") == 0)
    {
        if (getcwd(cwd, sizeof(cwd)) >= 0)
        {
            print(cwd);
            print("\n");
        }
        else
        {
            print("pwd failed\n");
        }
    }
    else if (strcmp(command, "cd") == 0)
    {
        long ret;

        if (!argument)
        {
            print("Usage: cd <directory>\n");
        }
        else
        {
            ret = chdir(argument);

            if (ret < 0)
                print("cd_failed\n");
            else
                print("cd_ok\n");
        }
    }

    else
    {
        print("Unknown command\n");
    }
}
}