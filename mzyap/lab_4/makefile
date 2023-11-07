all:
	gcc -g -ggdb -c -o clab_4.o clab_4.c
	nasm -g -f elf64 alab_4.asm -l alab_4.lst -F dwarf
	gcc -o ctest clab_4.o alab_4.o -fno-pie -no-pie
	rm *.o *.lst