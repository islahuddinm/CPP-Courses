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

int main() {
    OuterClass outer;
    OuterClass::InnerClass inner;

    outer.show();
    inner.display();

    return 0;
}
