as --32 boot.s -o boot.o
gcc -m32 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
ld -m elf_i386 -T linker.ld kernel.o boot.o -o Pelix.bin
grub-file --is-x86-multiboot Pelix.bin
mkdir -p Pelix/boot/grub
cp Pelix.bin Pelix/boot/Pelix.bin
cp grub.cfg Pelix/boot/grub/grub.cfg
grub-mkrescue -o Pelix.iso Pelix
qemu-system-x86_64 -cdrom Pelix.iso
