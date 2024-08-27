#include <iostream>

class ClassA {
public:
    static void staticFunction() {
        std::cout << "Static function in ClassA called!" << std::endl;
    }
};

class ClassB {
public:
    void callClassAStaticFunction() {
        ClassA::staticFunction(); // Call the static function directly using the class name
    }
};

int main() {
    ClassB objB;
    objB.callClassAStaticFunction();
    return 0;
}
