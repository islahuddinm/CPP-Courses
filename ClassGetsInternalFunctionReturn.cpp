#include <iostream>

class MyClass {
public:
    int getValue() {
        return 42; // Some computation or value
    }

    void displayValue() {
        int value = getValue(); // Calling the member function
        std::cout << "The value is: " << value << std::endl;
    }
};

int main() {
    MyClass obj;
    obj.displayValue(); // Output: The value is: 42
    return 0;
}
