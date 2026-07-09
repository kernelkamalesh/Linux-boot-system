#include "input.h"
#include "syscall.h"

long input(char *buf, long size)
{
    return read(0, buf, size);
}