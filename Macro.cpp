#include <iostream>


/* Macros in Unreal Engine and standard C++ are similar in concept, as they both rely on the preprocessor to
perform text substitution. Examples in C++ include #define PI 3.14159, #define SQUARE(x) ((x) * (x)),
and #ifdef DEBUG. */


#define PI 3.14159

/* int main() {
    double area = PI * 5 * 5;
    return 0;
} */


#define SQUARE(x) ((x) * (x))

int main() {
    int result = SQUARE(5); // result is 25
    return 0;
}
