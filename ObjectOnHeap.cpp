#include <iostream>

class Base {
public:
    int baseValue;
    Base(int v) : baseValue(v) {
        std::cout << "Base class constructor called" << std::endl;
    }
    virtual void display() {
        std::cout << "Base Value: " << baseValue << std::endl;
    }
    virtual ~Base() {
        std::cout << "Base class destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    int derivedValue;
    Derived(int baseVal, int derivedVal) : Base(baseVal), derivedValue(derivedVal) {
        std::cout << "Derived class constructor called" << std::endl;
    }
    void display() override {
        std::cout << "Base Value: " << baseValue << ", Derived Value: " << derivedValue << std::endl;
    }
    ~Derived() {
        std::cout << "Derived class destructor called" << std::endl;
    }
};

int main() {
    // Creating a derived class object on the heap
    Derived* obj = new Derived(10, 20);
    
    // Accessing the derived class's member function
    obj->display();

    Base* obj2 = new Derived(30, 20);
    obj2->display();
    
    // Deleting the derived class object to free the allocated memory
    delete obj;
    delete obj2;
    
    return 0;
}
