#include <iostream>

void outerFunction() {
    class InnerClass {
    public:
        int innerFunction(int x) {
            return x * x;
        }
    };

    InnerClass innerObject;
    int result = innerObject.innerFunction(5);
    std::cout << "Result: " << result << std::endl;
}

int main() {
    outerFunction();
    return 0;
}
