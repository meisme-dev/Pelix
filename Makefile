CFLAGS = 	-m32 \
			-c \
			-std=gnu99 \
			-ffreestanding \
			-O2	 \
			-Wall \
			-Wextra	\

LDFLAGS = 	-m elf_i386 \

prep:
	mkdir -p isodir/boot/grub
	mkdir -p build
	as --32 boot.s -o build/boot.o
	gcc -m32 -c kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -masm=intel
	ld -m elf_i386 -T linker.ld build/kernel.o build/boot.o -o Pelican.bin
	./grub.sh
	grub-mkrescue -o Pelican.iso isodir
	cp grub.cfg isodir/boot/grub/grub.cfg
	mv Pelican.bin isodir/boot/Pelican.bin
	mv Pelican.iso isodir/boot/Pelican.iso

clean:
	rm -r boot
	rm -r build

run:
	qemu-system-x86_64 -cdrom isodir/boot/Pelican.iso