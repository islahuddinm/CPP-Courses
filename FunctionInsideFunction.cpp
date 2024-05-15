#include <iostream>

void outerFunction() {
    auto innerFunction = [](int x) {
        return x * x;
    };

    int result = innerFunction(5);
    std::cout << "Result: " << result << std::endl;
}

int main() {
    outerFunction();
    return 0;
}
