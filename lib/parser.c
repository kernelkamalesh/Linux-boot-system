#include "strchr.h"
#include "parser.h"


void parse(char *buffer, char **command, char **argument)
{
    char *space;

    *command = buffer;
    *argument = 0;

    space =  strchr(buffer, ' ');

    if (space)
    {
        *space = '\0';
        *argument = space + 1;
    }

}