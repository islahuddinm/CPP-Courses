#include <iostream>
#include <stdexcept>

int main() {
    try {
        int age;

        std::cout << "Enter your age: ";
        std::cin >> age;

        if (age < 0) {
            throw std::runtime_error("Age cannot be negative");
        }

        std::cout << "Your age is " << age << '\n';
    }
    catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << '\n';
    }

    return 0;
}

/*

How it works:

    </c++>

        try {
        // Code that may cause an error
        }
        catch (...) {
            // Code that handles the error
        }

*/