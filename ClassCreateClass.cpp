#include <iostream>

class OuterClass {
public:
    class InnerClass {
    public:
        void display() {
            std::cout << "This is the InnerClass inside OuterClass." << std::endl;
        }
    };

    void show() {
        std::cout << "This is the OuterClass." << std::endl;
    }
};


// we cannot create function inside function, but we can create lambda function inside function.
void coba() {
    void coba1() {
        std::cout << "Try to print function inside functon\n";
    }
}
/* like so
void outerFunction() {
    auto innerFunction = []() {
        std::cout << "This is an inner function!" << std::endl;
    };

    // Call the inner (lambda) function
    innerFunction();
}*/


int main() {
    OuterClass outer;
    OuterClass::InnerClass inner;

    outer.show();
    inner.display();
    coba();

    return 0;
}
