#include <iostream>
using namespace std;

class ClassA {
public:
    int a;
    ClassA(int a) : a(a) {} // Constructor that initializes 'a'
};

class ClassB {
public:
    ClassA objA; // Object of ClassA as a member of ClassB, initialized with 42
    ClassA objC{50};

    // Constructor of ClassB that initializes objA
    ClassB(int a) : objA(a) {}
};

int main() {
    ClassB objB(42); // Creating object of ClassB and initializing it with 42
    cout << objB.objA.a << endl; // Accessing 'a' from objA inside objB
    cout << objB.objC.a << endl;
    return 0;
}