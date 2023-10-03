#include <stdio.h>

#define CHILD_OPAL_CARD 0
#define ADULT_OPAL_CARD 1
#define STUDENT_OPAL_CARD 2

struct person {
    int shoe_size;
    double height;
    char first_name_initial;
};

struct student {
    int id;
    int year;
    // int opal_type;
    // ^ Replaced by the following enum
    enum opal_card_type type;
}

enum opal_card_type {
    CHILD,
    ADULT,
    STUDENT,
};

int main() {
    // Note that <struct student> is the type here and not just <struct> by itself
    struct student john;
    john.id = 5500001;
    john.year = 1;
    john.opal_card_type = opal_card_type.STUDENT;

    // Alternative way to initialise our struct, using {}, and entering values in order
    struct student jane = { 5400002, 3, opal_card_type.STUDENT };

    // We can even directly scan into the struct from input
    struct person bob;
    scanf("%d %lf %c", &bob.shoe_size, &bob.height, &bob.first_name_initial);
}
