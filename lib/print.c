#include "print.h"
#include "string.h"
#include "syscall.h"

void print(const char *str)
{
    write(1, str, strlen(str));
}
