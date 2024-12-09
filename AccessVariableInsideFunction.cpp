#include <iostream>

int computeValue() {
    return 42; // Some computation or value
}

int variable() {
    int val = 10;
}

void getVariable() {
    val = 15; // we need "return" like computeValue() function.
}

class MyClass {
public:
    
    void displayValue() {
        int value = computeValue(); // Calling the non-member function
        std::cout << "The value is: " << value << std::endl;
    }

    int var() {
        int inte = 0;
    }

    int getVar() {
        inte = 0; // we need "return" like computeValue() function.
    }
};

int main() {
    MyClass obj;
    obj.displayValue(); // Output: The value is: 42
    return 0;
}
