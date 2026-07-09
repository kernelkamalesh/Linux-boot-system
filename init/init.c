#include "syscall.h"
#include "string.h"
#include "print.h"
#include "input.h"

void kmain(void)
{
char buffer[128];

while (1)
{
    print("mysh> ");

    long n = input(buffer, sizeof(buffer) - 1);

    buffer[n] = '\0';

    print(buffer);
}
}
