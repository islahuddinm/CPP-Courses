#include <iostream>

/* 'dynamic_cast' is a keyword in C++ used for converting pointers or references of base class to pointers or
references of derived class at runtime. It's primarily used in situations where you have a base class pointer
or reference pointing to a derived class object, and you want to safely downcast it to the derived class type.*/

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void specificFunction() {
        std::cout << "Called specificFunction in Derived class\n";
    }
};

class Child : public Derived {
public:
    void childFunction() {
        std::cout << "Called childFunction in Derived class\n";
    }
};

int main() {
    Base* basePtr;
    
    /* 
    //Base* basePtr = new Derived;
    we would be failed because we dont have any "child class" information.
    it should be "Base* basePtr = new Child;" instead of "Base* basePtr = new Derived;". */
    //Child* derivedPtr = dynamic_cast<Child*>(basePtr);
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        //derivedPtr->childFunction();
        derivedPtr->specificFunction();
    } else {
        std::cout << "dynamic_cast failed\n";
    }

    delete basePtr;
    return 0;
}

/* In this example, 'basePtr' is a pointer to a 'Base' class object that actually points to a 'Derived' class object.
The 'dynamic_cast' is used to safely convert 'basePtr' to a `Derived.*/