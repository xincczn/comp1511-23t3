#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *ptr = malloc(sizeof(int));
    *ptr = 42;
    printf("Value: %d\n", *ptr);

    // Every malloc function call we make during the runtime of our program must be 
    // matched by a free function call.
    // Comment below to see error message
    // Compile via: dcc --leak-check free.c -o free
    free(ptr);

    return 0;
}
