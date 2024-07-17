CC = i686-elf-gcc
AS = i686-elf-as
CFLAGS = -ffreestanding -O2

kernel:
	$(AS) boot.s -o ../../target/boot.o
	$(CC) -c kernel.c -o ../../target/kernel.o $(CFLAGS) -Wall -Wextra -std=gnu99
	$(CC) -T ../../linker.ld -o ../../target/kernel.bin $(CFLAGS) -nostdlib ../../target/boot.o ../../target/kernel.o -lgcc
