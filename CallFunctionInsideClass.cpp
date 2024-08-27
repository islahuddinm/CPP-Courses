#include <iostream>

class MyClass {
public:

    // this is "static function". We can call static functions without an object.
    static void myStaticFunction() {
        std::cout << "Calling a static function without creating an object!" << std::endl;
    }
};

int main() {
    // Call the static function without creating an object
    MyClass::myStaticFunction();
    return 0;
}
