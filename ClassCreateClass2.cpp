#include <iostream>

class OuterClass {
private:
    int privateMember;

public:
    OuterClass() : privateMember(100) {}

    class InnerClass {
    public:
        void display(OuterClass& outer) {
            std::cout << "Accessing OuterClass's privateMember: " << outer.privateMember << std::endl;
        }
    };
};

int main() {
    OuterClass outer;
    OuterClass::InnerClass inner;

    inner.display(outer);

    return 0;
}
