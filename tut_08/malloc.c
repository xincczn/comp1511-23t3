#include <stdio.h>
#include <stdlib.h>  // malloc is defined in stdlib

#define ARRAY_SIZE 3

struct box {
    int item_i;
    char item_c;
    double item_d;
};


// Main
int main() {
    //========== What is malloc? ==========
    /*
        <return_type> <function_name>(<parameters>);

        void *malloc(size_t size);
        
        void * -> Returns a pointer to the allocated memory
        size_t -> type which is a funky alias for int
        size   -> A number for amount of memory to allocate
    */

    // We can use sizeof(data_type) to determine the size of a type
    // Don't worry about %lu, its just to print funky size_t types
    printf("Size of Int: %lu\n", sizeof(int));
    printf("Size of Char: %lu\n", sizeof(char));
    printf("Size of Double: %lu\n", sizeof(double));

    //========== Allocate memory for primitive data types ==========
    double num = 42.42;

    // Use malloc to allocate enough memory for an integer
    double *num_d = malloc(sizeof(double));
    *num_d = 18.18;

    printf("Static memory: %.2lf\n", num);
    printf("Dynamic memory: %.2lf\n", *num_d);

    //========== Allocate memory for an array ==========

    // Size of array -> amount of elements * size of an element
    int *array_d = malloc(ARRAY_SIZE * sizeof(int));

    array_d[0] = 1;
    array_d[1] = 2;
    array_d[2] = 3;

    printf("Dynamic Array: [ ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array_d[i]);
    }
    printf("]\n");

    // Prove we allocated the right amount of memory
    // printf("Shouldn't compile: %d\n", array_d[3]);

    //========== Allocate memory for a struct ==========
    // Size of struct box
    printf("Size of Struct Box: %lu\n", sizeof(struct box));

    // Allocate like before, use -> instead of . since struct pointer
    struct box *new_box = malloc(sizeof(struct box));
    new_box->item_i = 1;
    new_box->item_c = '2';
    new_box->item_d = 3.0;

    printf("Dynamic Struct Box: {\n");
    printf("\titem_i: %d\n", new_box->item_i);
    printf("\titem_c: %c\n", new_box->item_c);
    printf("\titem_d: %.1lf\n", new_box->item_d);
    printf("}\n");
}
