#include <stdio.h>
#include <stdlib.h>

// double number = 32;

// void *malloc(size_t size);
// <return_type> <function_name>(<parameters> ...);

int *return_zeroes() {
    int size = 5;
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
    return array;
}

int main() {
//     printf("Size of Char: %lu\n", sizeof(char));
//     printf("Size of Int: %lu\n", sizeof(int));
//     printf("Size of Double: %lu\n", sizeof(double));
//     printf("Size of Pointers: %lu %lu %lu\n", sizeof(char *), sizeof(int *), sizeof(double *));

    int *array = return_zeroes();

    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
}