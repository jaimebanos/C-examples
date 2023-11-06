# Compiler and flags
CC = gcc

help:
	@echo "Targets:"
	@echo "  run    : Compile and run the C/C++ program"
	@echo "  clean  : Remove autogenerated files"
	@echo "  help   : Display this help message"

run: main
	@./build/main

main: Calculadora/main.c
	@$(CC) -o build/main Calculadora/main.c

clean:
	@rm -vf build/main