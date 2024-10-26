#include "../src/libbpf.h"

int callback_fn(struct bpf_program *prog, struct bpf_prog_load_opts *opts, long cookie) {
    printf("Hello world\n");
    return -1;
}

int main(int argn, char **argv) {
    if (argn != 3) {
        return 1;
    }
    struct bpf_object  *obj  = bpf_object__open(argv[1]);
    struct bpf_program *prog = bpf_object__find_program_by_name(obj, argv[2]);
    if (!prog) {
        return 1;
    }

    struct libbpf_prog_handler_opts opts;
    opts.sz                   = sizeof(opts);
    opts.prog_attach_fn       = NULL;
    opts.prog_setup_fn        = NULL;
    opts.prog_prepare_load_fn = callback_fn;
    libbpf_register_prog_handler(bpf_program__section_name(prog), bpf_program__get_type(prog),
                                 bpf_program__expected_attach_type(prog), &opts);
    bpf_object__close(obj);
    obj = bpf_object__open(argv[1]);

    bpf_object__load(obj, 0, "asd", "fddffd");

    bpf_object__close(obj);
}
