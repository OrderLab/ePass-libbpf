# Prog load call chain

LIBBPF_API int bpf_object__load -> bpf_object__load -> bpf_object_load -> bpf_object__load_progs -> bpf_object_load_prog -> syscall