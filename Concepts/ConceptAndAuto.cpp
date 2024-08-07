#include <iostream>

std::integral auto add(std::integral auto a, std::integral auto b) {

    return a + b;
}

int main() {

    std::integral auto x = add(10, 20);
    std::floating_point auto x = add(10, 20); // errors because parameter values are not 'float values'

    std::cout << x << std::endl;

    return 0;
}