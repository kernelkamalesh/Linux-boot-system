#include "syscall.h"

void kmain(void)
{
    char msg[] = "Hello from my own init!\n";

    write(1, msg, 25);

    for (;;)
        ;
}