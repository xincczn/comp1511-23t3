// Xing He, (z5413977), 03/10/23
// Part 4.5: Functions Practice

#include <stdio.h>

struct student {
    int wallet;
    int savings;
    int assets;
};

// Net Worth = 1 x wallet + 2 x savings + 3 x assets

int calculate_net_worth(struct student student) {
    return student.wallet + 2 * student.savings + 3 * student.assets;
}

void print_rich_students(struct student students[4]) {
    printf("Net Worth:\n");
    int i = 0;
    while (i < 4) {
        int worth = calculate_net_worth(students[i]);
        if (worth >= 5000) {
            printf("Student %d: %d\n", i + 1, worth);
        }
        i++;
    }
}

void print_not_rich_students(struct student students[4]) {
    printf("Net Worth:\n");
    int i = 0;
    while (i < 4) {
        int worth = calculate_net_worth(students[i]);
        if (worth < 5000) {
            printf("Student %d: %d\n", i + 1, worth);
        }
        i++;
    }
}



int main(void) {
    struct student students[4] = {
        { 1000, 1000, 3000 },
        { 3000, 103, 223 },
        { 2131, 1232, 123 },
        { 1231, 1232, 1111}
    };

    print_rich_students(students);

    print_not_rich_students(students);

    return 0;
}
