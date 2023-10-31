#include <stdio.h>
#include <stdlib.h>

int array[10]


int *create_array() {
    // size of array * size of the type
    int *array = malloc(5 * sizeof(int));
    array = realloc(array, 20 * sizeof(int))

    for (int i = 0; i < 5; i++) {
        array[i] = i + 1;
    }

    return array;
}

int main() {

    int *array = create_array();
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);


    // printf("Size of Char: %lu\n", sizeof(char));
    // printf("Size of Int: %lu\n", sizeof(int));
    // printf("Size of Double: %lu\n", sizeof(double));
    // printf("Size of Pointers: %lu %lu %lu\n", sizeof(char *), sizeof(int *), sizeof(double *));

}