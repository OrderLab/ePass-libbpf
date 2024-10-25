
main:
	make -C ../src -j20
	gcc -o main main.c -L../src -lbpf

run: main
	LD_LIBRARY_PATH=../src ./main test.o prog

.PHONY: main
