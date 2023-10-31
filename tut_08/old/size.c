#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Size of Char: %lu\n", sizeof(char));      // 1
    printf("Size of Int: %lu\n", sizeof(int));        // 4
    printf("Size of Double: %lu\n", sizeof(double));  // 8
    printf("Size of Pointers: %lu %lu %lu\n", sizeof(char *), sizeof(int *), sizeof(double *));
}
