
main:
	make -C ../src -j20
	gcc -o main main.c -L../ePass/core/build -lepass -L../src -lbpf

run: main
	LIBBPF_ENABLE_EPASS=1 LIBBPF_EPASS_GOPT="verbose=3" LD_LIBRARY_PATH=../src ./main test.o prog

.PHONY: main
