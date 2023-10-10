// Xing He, (z5413977), 03/10/23
// Part 3: Scanning in Loops (variable number of inputs)

#include <stdio.h>

int main(void) {

    // Refer to scanf_return.c to understand this code further

    // New Sypnopsis: We now have an unknown amount of students, find the new mean

    double average = 0.0;
    int num_of_students = 0;

    printf("Verbose version!\n");
    // Verbose version, we store the return value into `result`
    printf("Input Age: ");
    int student_age = 0;
    int result = scanf(" %d", &student_age);

    while (result == 1) {
        average += student_age;
        num_of_students++;

        printf("Input Age: ");
        result = scanf(" %d", &student_age);
    }

    printf("Average age: %.2lf", average / num_of_students);


    // Concise version, we directly call the scanf and compare within the loop condition
    // As you can see, the concise version simply scans and compares during the evaluation of the loop
    // I recommend using the second one once you are more comfortable with scanf and loops
    // As it is more cleaner to reader
    // Try swapping them out/uncomment this and comment the verbose version to try them out
    /*
        printf("Input Age: ");
        while (scanf(" %d", &student_age) == 1) {
            average += student_age;
            num_of_students++;

            printf("Input Age: ");
        }
    */

    return 0;
}