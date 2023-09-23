// Xing He, (z5413977), 19/09/23
// Part 1: Calculating Values in Programs
// Part 2: Weird Data Types and Arithmetic
#include <stdio.h>

int main(void) {

    /*
        int -> 10
        double -> 3.14
        char -> 'a'

        <type> <variable_name> = <value>;
    */


    int number = 10;
    double pi = 3.14;
    char letter = 'a';

    printf("number = %d\n", number);
    printf("pi = %lf\n", pi);
    printf("letter = %c\n", letter);


    int a = 10;
    int b = 5;
    int sum = a + b;

    printf("sum = %d\n", sum);

    // ----------------------------------------
    printf("\n\n");

    /*
        Rules:
            int + int -> int
            double + double -> double
            double + int -> double
    */

    int answer_1 = 7 / 2;
    printf("Sensible answer: 3.5\n");
    printf("C answer: %d\n", answer_1);


    double answer_2 = (3.0 / 2) + 1;
    printf("Sensible answer: 2.5\n");
    printf("C answer: %lf\n", answer_2);

    // Bonus question
    double answer_2_1 = (3 / 2) + 1.0;
    printf("Sensible answer: 2.5\n");
    printf("C answer: %lf\n", answer_2_1);

    char answer_3 = 'a' + 5;
    printf("Sensible answer: (a + 5) / (a = -5)\n");
    printf("C answer: %c\n", answer_3);
    printf("Reason: %d\n", answer_3);
    // char have numerical representation which is used here
    // C: 97 + 5 == 102

    char answer_4 = 'F' - 'A' + 'a';
    printf("Sensible answer: Error\n");
    printf("C answer: %c\n", answer_4);
    printf("Reason: %d\n", answer_4);
    // 'A' - 'a' is 32, which is the exact offset between uppercase and lowercase
    // letters, hence why adding 32 to 'F' turn it into 'f'
    // C: 102 => 'f'


    return 0;
}