# makefile for quontient.asm
task: main.c input.c inrnd.c output.c quontient.o
	gcc -g -o task main.c input.c inrnd.c output.c quontient.o -no-pie
quontient.o: quontient.asm
	nasm -f elf64 -g -F dwarf quontient.asm -l quontient.lst