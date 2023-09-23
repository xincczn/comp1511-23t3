// Xing He, (z5413977), 19/09/23
// Part 4: Pratical Programming Exercise 

#include <stdio.h>

int main(void) {

    /*
        Pseudocode code
        Note: pseudocode isn't real code 

        int a
        int b
        scan(a, b)
        if (a < b)
            print(error)
        else if (b == 0)
            print(error)
        else if (a > b)
            print(a / b)
            print((a * 1.0) / (b * 1.0))
    */

    // Translated code
    int a = 0;
    int b = 0;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a < b) {
        printf("error: %d is smaller than %d\n", a, b);
    } else if (b == 0) {
        printf("error: b is %d\n", b);
    } else if (a > b) {
        printf("%d\n", a / b);
        printf("%lf\n", (a * 1.0) / b * 1.0);
    }

    return 0;
}