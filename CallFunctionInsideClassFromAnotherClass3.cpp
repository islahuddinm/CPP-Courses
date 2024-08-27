#include <iostream>

class ClassA {
public:
    void show() {
        std::cout << "Function in ClassA called!" << std::endl;
    }
};

class ClassB {
public:
    void callFunction(ClassA& objA) {
        objA.show(); // Call the function using the passed object
    }
};

int main() {
    ClassA objA;
    ClassB objB;
    objB.callFunction(objA); // Pass objA to objB
    return 0;
}
