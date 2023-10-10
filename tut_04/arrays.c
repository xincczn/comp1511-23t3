// Xing He, (z5413977), 10/10/23
// Part 0: Quick Recap

#include <stdio.h>

#define ARRAY_SIZE 5

int main(void) {

    // Arrays allow us to save multiple values of the same type into one central source
    // Declaration is similar to normal variables except we add [] to the end of
    // variable name with a number which determines its size

    // Example: array that holds integers
    int numbers[3];
    // We can then initialise the elements in our array by calling the variable
    // name with the index (position)
    // Note: Array positions start at 0 not 1
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;


    // We can also initialise the array during declaration if the values are all
    // known like this
    double decimals[ARRAY_SIZE] = { 1.0, 2.0, 3.0, 4.0, 5.0 };


    // Lastly, we can initialise the array with zeros with this syntax
    double zeroes[ARRAY_SIZE] = { 0 };

    // The best feature of arrays is how we can iterate through each element
    // via a while loop
    
    // Standard array while loop structure
    int i = 0;  // Arrays start at 0
    while (i < ARRAY_SIZE) {  // Condition less than ARRAY_SIZE prevents overflow
        printf("%lf ", zeroes[i]);  // Body of loop executes on element
        i++;
    }
    printf("\n");

    return 0;
}