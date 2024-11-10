#include "../src/libbpf.h"

int main(int argn, char **argv) {
    if (argn != 3) {
        return 1;
    }
    struct bpf_object  *obj  = bpf_object__open(argv[1]);
    struct bpf_program *prog = bpf_object__find_program_by_name(obj, argv[2]);
    if (!prog) {
        return 1;
    }

    bpf_object__load(obj, 1, "asd", "fddffd");

    bpf_object__close(obj);
}
