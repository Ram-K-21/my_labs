all:
	gcc -g -ggdb -c -o clab_2.o clab_2.c
	nasm -g -f elf64 alab_2.asm -l alab_2.lst -F dwarf
	gcc -o ctest clab_2.o alab_2.o -fno-pie -no-pie
	rm *.o *.lst