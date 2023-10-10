// Xing He, (z5413977), 03/10/23
// Part 2: Scanning in Loops (fixed number of inputs)

#include <stdio.h>

#define SIZE 5

int main(void) {

    int array[SIZE] = { 0 };

    // Loop which scans user input into our array
    int i = 0;
    while (i < SIZE) {
        scanf("%d", &array[i]);
        i++;
    }

    // Print array out
    int j = 0;
    while (j < SIZE) {
        printf("%d ", array[j]);
        j++;
    }
    printf("\n");

    return 0;
}