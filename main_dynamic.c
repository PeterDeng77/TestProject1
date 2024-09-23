// main_dynamic.c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*add)(int, int);
    char *error;

    handle = dlopen("./libadd.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    *(void **)(&add) = dlsym(handle, "add");
    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    int result = add(3, 5);
    printf("完全动态链接，两数和为: %d\n", result);

    dlclose(handle);
    return 0;
}
