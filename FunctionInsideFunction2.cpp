#include <iostream>

// C++ does not allow defining a function inside another function. Unlike some languages,
// functions must be defined at namespace/class scope.

void coba() {
    void coba1(); {
        std::cout << "Try to print function inside functon\n";
    }
}

int main() {

    return 0;
}

// If you want a function only inside coba()
// Use a lambda:

#include <iostream>

void coba() {
    auto coba1 = []() {
        std::cout << "Try to print function inside function\n";
    };

    coba1();
}

int main() {

    coba();

    return 0;
}