#include <iostream>

/* class Employee {
public:
    void working() {
        std::cout << "Employee is working." << std::endl;
    }

    static void staticWorking() {
        std::cout << "Employee is static working." << std::endl;
    }
};

int main() {

    Employee emp;
    // this is static binding.
    emp.working();
    
    return 0;
} */

class Base {
public:
    void display() {
        std::cout << "Base class display() called." << std::endl;
    }
};

class Derived : public Base {
public:
    void display() {
        std::cout << "Derived class display() called." << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    Base *ptr = &derivedObj; // Pointer of Base type pointing to Derived object

    // Static binding: Resolved at compile time based on the pointer type (Base)
    ptr->display(); // This will call Base::display(), not Derived::display()

    return 0;
}