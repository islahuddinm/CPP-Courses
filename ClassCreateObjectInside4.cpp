#include <iostream>
using namespace std;

class ClassA {
public:
    int a;
    ClassA(int a) : a(a) {} // Constructor that initializes 'a'

    void print() {
        cout << "ClassA object - a: " << a << endl;
    }
};

class ClassB {
public:
    ClassA objA; // Object of ClassA as a member of ClassB, initialized with 45
    ClassA objB{42}; // Object of ClassA as a member of ClassB, initialized with 42

    // Constructor of ClassB that initializes objA
    ClassB(int a) : objA(a) {}

    void print() {
        cout << "ClassB object - objA.a: " << objA.a << endl;
        objA.print(); // Print objA
        cout << "ClassB object - objB.a: " << objB.a << endl;
        objB.print(); // Print objB
    }
};

int main() {
    ClassB objB(45); // Creating object of ClassB and initializing it with 45
    objB.print(); // Printing the object objB and objA
    return 0;
}
