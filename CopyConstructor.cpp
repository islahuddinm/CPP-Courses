#include <iostream>

class Example {
private:
    int *data;
public:
    // Constructor
    Example(int value) {
        data = new int(value);

        std::cout << "Parameterd constructor" << '\n';
    }

    // Copy Constructor
    Example(const Example &source) {
        data = new int(*source.data);  // deep copy

        std::cout << "Copy constructor" << '\n';
    }
};

int main() {
    Example obj1(42);      // Original object
    Example obj2 = obj1;   // Copy object, created using the copy constructor

    return 0;
}
