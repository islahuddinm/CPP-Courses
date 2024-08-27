#include <iostream>

class ClassA {
public:
    void nonStaticFunction() {
        std::cout << "Non-static function in ClassA called!" << std::endl;
    }
};

class ClassB {
public:
    void callClassANonStaticFunction() {
        ClassA objA; // Create an instance of ClassA
        objA.nonStaticFunction(); // Call the non-static function using the object
    }
};

int main() {
    ClassB objB;
    objB.callClassANonStaticFunction();
    return 0;
}
