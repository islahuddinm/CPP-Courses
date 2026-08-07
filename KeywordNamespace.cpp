#include <iostream>

//compiler will always start to read top project to below then start to working in main fuction (int main)

//namespace (A namespace in C++ is a feature used to organize code into logical groups and prevent name collision)

namespace first{
    int x = 2;
}

namespace second{
    int x = 3;
    void printArea() {
        std::cout << "Area: " << x * x << '\n';
    }
}

int main(){
    
    int x = 0;
   
    std::cout << first::x << '\n';
    std::cout << x << '\n';
    
    second::printArea(); // Call the function from the 'second' namespace

    return 0; //a way for main function send the message to user that this task is success or there are problems.
}