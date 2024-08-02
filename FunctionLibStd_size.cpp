#include <iostream>

int main() {

    int random[7] = {};
    std::string names[] = {"john", "carry", "gordon", "max"}; //we also can do without assign amount of array value in range, it will be fill automatically according to amount of array value in range

    for (int i = 0; i < std::size(names); i++) {

        std::cout << "names of employee is " << names[i] << '\n';
    }

    for (int i = 0; i < std::size(random); i++) { //it is for make random value

        random[i] = rand();

        std::cout << "random value is " << random[i] << '\n';
    }

    return 0;
}