#include <iostream>

/* 'friend' keyword is used to give a non-member function access to private and protected members of a class.
it means that a function that is not part of the class itself can still access the private and protected data
of the class. */

/* class MyClass {
private:
    int data;

public:
    MyClass(int value) : data(value) {}

    // Declaring the non-member function as a friend
    friend void showData(MyClass obj);
};

// Definition of the non-member function
void showData(MyClass obj) {
    // Now it can access the private member 'data'
    std::cout << "Data: " << obj.data << std::endl;
}

int main() {
    MyClass obj(42);
    showData(obj); // Outputs: Data: 42
    return 0;
} */

using namespace std;

class ClassA;
class ClassB;

class ClassA {
private:
    int dataA;

public:
    ClassA(int value) : dataA(value) {}

    // Declare a friend function that can access private members of ClassA
    friend void showData(const ClassA& objA, const ClassB& objB);
};

class ClassB {
private:
    int dataB;

public:
    ClassB(int value) : dataB(value) {}

    // Declare a friend function that can access private members of ClassB
    friend void showData(const ClassA& objA, const ClassB& objB); // this "(const ClassA& objA, const ClassB& objB)" is create object in parameter
};

// Friend function that accesses private members of both ClassA and ClassB
void showData(const ClassA& objA, const ClassB& objB) {
    cout << "Data from ClassA: " << objA.dataA << endl;
    cout << "Data from ClassB: " << objB.dataB << endl;
}

int main() {
    ClassA objA(10);
    ClassB objB(20);

    showData(objA, objB); // Outputs: Data from ClassA: 10 | Data from ClassB: 20

    return 0;
}