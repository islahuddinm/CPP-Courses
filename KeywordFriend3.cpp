#include <iostream>
using namespace std;

/* 'friend' keyword is used to give a non-member function access to private and protected members of a class.
it means that a function that is not part of the class itself can still access the private and protected data
of the class. */

class ClassB;
class ClassC;

class ClassA {
private:
    int dataA;

public:
    ClassA(int value) : dataA(value) {}

    // Declare ClassB and ClassC as friends
    friend class ClassB;
    friend class ClassC;
};

class ClassB {
public:
    void showData(const ClassA& obj) { // this "(const ClassA& obj)" is crreate object in parameter.
        // Can access private members of ClassA
        cout << "ClassB accessing ClassA: " << obj.dataA << endl;
    }
};

class ClassC {
public:
    void showData(const ClassA& obj) {
        // Can access private members of ClassA
        cout << "ClassC accessing ClassA: " << obj.dataA << endl;
    }
};

int main() {
    ClassA objA(30);
    ClassB objB;
    ClassC objC;

    objB.showData(objA); // Outputs: ClassB accessing ClassA: 30
    objC.showData(objA); // Outputs: ClassC accessing ClassA: 30

    return 0;
}
