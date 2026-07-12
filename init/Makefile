CC      = gcc
AS      = gcc
LD      = ld

CFLAGS  = -ffreestanding -fno-stack-protector -mno-red-zone -nostdlib -nostartfiles -I../include
ASFLAGS = -c
LDFLAGS = -T linker.ld

all: init

init: start.o init.o syscall.o string.o print.o input.o string_compare.o strchr.o parser.o
	$(LD) $(LDFLAGS) -o init start.o init.o syscall.o string.o print.o input.o string_compare.o strchr.o parser.o

start.o: start.S
	$(AS) $(ASFLAGS) start.S -o start.o

init.o: init.c
	$(CC) $(CFLAGS) -c init.c -o init.o

syscall.o: syscall.S
	$(AS) $(ASFLAGS) syscall.S -o syscall.o

string.o:
	$(CC) $(CFLAGS) -c ../lib/string.c -o string.o

print.o:
	$(CC) $(CFLAGS) -c ../lib/print.c -o print.o

input.o:
	$(CC) $(CFLAGS) -c ../lib/input.c -o input.o

string_compare.o:
	$(CC) $(CFLAGS) -c ../lib/string_compare.c -o string_compare.o

strchr.o:
	$(CC) $(CFLAGS) -c ../lib/strchr.c -o strchr.o

parser.o:
	$(CC) $(CFLAGS) -c ../lib/parser.c -o parser.o
 
clean:
	rm -f *.o init