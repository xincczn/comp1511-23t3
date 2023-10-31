#include <stdio.h>

// 1. do this
// 2. do that
int main(int argc, char *argv[]) {
    // argc -> Argument Count
    printf("argc: %d\n", argc);
    // argc -> Argument Vector
    printf("argv: [");
    for (int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("]\n");
    return 0;
}
