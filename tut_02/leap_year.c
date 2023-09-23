// Xing He, (z5413977), 19/09/23
// Part 3: Diagramming

#include <stdio.h>

int main(void) {

    // Declare and initialise a variable
    int year = 0;

    // Prompt and scan in user input into variable
    printf("Enter year: ");
    scanf("%d", &year);

    // Direct translation of flowchart
    if (year % 400 != 0) {
        printf("Not a leap year!\n");
    } else if (year % 100 == 0) {
        printf("Not a leap year!\n");
    } else if (year % 4 != 0) {
        printf("Not a leap year!\n");
    } else {
        printf("Is a leap year!\n");
    }

    // === BONUS ===
    // To simplify further using logical and comparison operators 
    // if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
    //     printf("Is a leap year!\n");
    // } else {
    //     printf("Not a leap year!\n");
    // }

    return 0;
}