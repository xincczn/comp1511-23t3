#include <stdio.h>
#include <stdlib.h>

/*
    1. int array[]   o
    2. int array[5]  o
    3. int *array    o
    4. int array[6]  o
*/

void print_array(int size, int *array) {
    printf("==== Array ====\n");
    printf("Memory Address | Value\n");
    for (int i = 0; i < size; i++) {
        printf("%p | %d\n", array + i, *(array + i));
    }
}

int main(void) {
    int array[5] = {1, 2, 3, 4, 5};
    print_array(5, array);
}
