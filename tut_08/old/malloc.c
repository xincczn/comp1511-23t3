#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 3

int main() {

    double num = 40.0;

    // Use malloc to allocate enough memory for an integer
    double *num_d = malloc(sizeof(double));
    *num_d = 32.0;

    printf("Static memory: %lf\n", num);
    printf("Dynamic memory: %lf\n", *num_d);

    // Allocate enough memory for an array
    /*
        void *malloc(size_t size);
        <return_type> <function_name>(<parameters>);
        size_t -> alias for int
    */

    int *array_d = malloc(ARRAY_SIZE * sizeof(int));

    array_d[0] = 1;
    array_d[1] = 2;
    array_d[2] = 3;

    printf("Dynamic Array: [");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array_d[i]);
    }
    printf("]\n");
}
