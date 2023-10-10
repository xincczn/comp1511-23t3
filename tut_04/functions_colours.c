// Xing He, (z5413977), 03/10/23
// Part 4: Functions Practice

#include <stdio.h>

// RGB Representation
struct colour {
    int red;
    int green;
    int blue;
};

// Function Prototypes
struct colour make_colour(int red, int green, int blue);
int is_pink(struct colour light);

// Main Function
int main() {
    
    // pink: 255,192,203
    struct colour pink = make_colour(255, 192, 203);

    printf("Is it pink: %d\n", is_pink(pink));

    struct colour cyan = make_colour(0, 100, 100);

    printf("Is it pink: %d\n", is_pink(cyan));

    return 0;
}

// i = 0;
// return_type function_name(<... parameters>)
struct colour make_colour(int red, int green, int blue) {
    // type
    struct colour new_colour = {red, green, blue};

    // Alternative initialisation
    // new_colour.red = red;
    // new_colour.blue = blue;
    // new_colour.green = green;

    return new_colour;
}

int get_main_colour(struct colour c) {
    if (c.red > c.green && c.red > c.blue) {
        return c.red;
    } else if (c.green > c.red && c.green > c.blue) {
        return c.green;
    } else if (c.blue > c.red && c.blue > c.green) {
        return c.blue;
    } else {
        return 0;
    }
}

double brightness(struct colour colour) {
    return sqrt(colour.red) + sqrt(colour.green) + sqrt(colour.blue);
}

double average_brightness(struct colour colours[100], int size) {
    double avg = 0;

    int i = 0;
    while (i < size) {
        avg += brightness(colours[i]);
        i++;
    }

    return avg / size;
}

// returns true (1) if the light is pink and false (0) otherwise
int is_pink(struct colour light) {
    return light.red == 255 && light.green == 192 && light.blue == 203;
}

