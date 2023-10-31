#include <stdio.h>

/*
    Inside of the library stdio.h, alongside the functions
    printf(), scanf(), etc contains a defined constant

    #define EOF -1

    We can use this for our scanf loop (refer back to tutorial 5 for what -1 means)
*/

int main (void) {

    int input;
    while (scanf(" %c", &input) != EOF) {
        printf("Input: %d\n", input);
    }

    return 0;
}