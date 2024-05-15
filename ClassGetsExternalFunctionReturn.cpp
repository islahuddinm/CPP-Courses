#include <iostream>

int computeValue() {
    return 42; // Some computation or value
}

class MyClass {
public:
    void displayValue() {
        int value = computeValue(); // Calling the non-member function
        std::cout << "The value is: " << value << std::endl;
    }
};

int main() {
    MyClass obj;
    obj.displayValue(); // Output: The value is: 42
    return 0;
}
