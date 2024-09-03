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

    // this 'Base* basePtr;' is just a pointer declaration, not object creation.
    /* if pointer is declared but not initialized, it holds an indeterminate value (essentially garbage). */
    Base* basePtr;   
    Child* basePtr2;  
    
    // this is create object for polymorphism.
    Base* basePtr3 = new Derived; 
    
    // this would get error because 'specificFunction()' is not virtual function.
    // in default this also would get error because there is no 'specificFunction()' in base class.
    //basePtr3->specificFunction();
    
    /* 'dynamic_cast' is used to safely convert a pointer or reference from one type to another
    within a class hierarchy. */
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    
    if (derivedPtr == nullptr) {        
        derivedPtr->specificFunction();
    } else {
        std::cout << "dynamic_cast failed\n";
    }

    // this is used to check if 'basePtr2' is object. if 'basePtr2' is not 'nullptr' so it is object
    if(basePtr2 == nullptr) {
        basePtr2->childFunction();
    } else {
        std::cout << "basePtr2 is 'Object'\n";
    }    

    
    Derived* try1;
    Child* try2 = dynamic_cast<Child*>(try1);
    
    if(try2 == nullptr) {
        try2->childFunction();
    } else {
        std::cout << "dynamic_cast failed'\n";
    } 
    
    try1->specificFunction();

    
    delete basePtr;
    return 0;
}

/* In this example, 'basePtr' is a pointer to a 'Base' class object that actually points to a 'Derived' class object.
The 'dynamic_cast' is used to safely convert 'basePtr' to a `Derived.*/