all:
	gcc -g -ggdb -c -o clab_1.o clab_1.c
	nasm -g -f elf64 alab_1.asm -l alab_1.lst -F dwarf
	gcc -o ctest clab_1.o alab_1.o -fno-pie -no-pie
	rm *.o *.lst