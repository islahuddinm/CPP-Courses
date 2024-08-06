#include<iostream>

template <typename T>
T compare(T a, T b) {    
    
    return (a > b)? a : b; // this is ternary
}

int main() {

    int a = 7;
    int b = 5;

    int *aa = &a;
    int *bb = &b;

    // this is comparing address
    std::cout << compare(aa, bb) << std::endl; // this will print value's memory address.
    std::cout << compare(*aa, *bb) << std::endl; // if we give "*" at variable would print a value.

    return 0;
}