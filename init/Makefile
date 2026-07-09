CC      = gcc
AS      = gcc
LD      = ld

CFLAGS  = -ffreestanding -fno-stack-protector -mno-red-zone -nostdlib -nostartfiles
ASFLAGS = -c
LDFLAGS = -T linker.ld

all: init

init: start.o init.o syscall.o
	$(LD) $(LDFLAGS) -o init start.o init.o syscall.o

start.o: start.S
	$(AS) $(ASFLAGS) start.S -o start.o

init.o: init.c
	$(CC) $(CFLAGS) -c init.c -o init.o

syscall.o: syscall.S
	$(AS) $(ASFLAGS) syscall.S -o syscall.o

clean:
	rm -f *.o init