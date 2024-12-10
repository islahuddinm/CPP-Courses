#include <iostream>

/* Polymorphism(many forms) or concpept or method in C++ allows us to reuse code by creating one function
that's usable for multiple uses in different scenarios. we can call polymorphism is method to make values of
other class types to be part of current class type. */

class Animal {
public:
    // Virtual method to enable polymorphism
    virtual void speak() {
        std::cout << "Animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    // Override the speak method
    void speak() override {
        std::cout << "Woof!" << std::endl;
    }
};

int main() {

    Animal* animal = new Animal;
    //animal->speak();

    // Case 1: Dog* pointer
    Dog* no_animal = new Dog;
    no_animal->speak();  // Calls Dog's speak() method directly

    // Case 2: Animal* pointer (polymorphism)
    Animal* p_animal = new Dog;
    // This is dynamic binding cuz virtual function. If we do not give virtual, it would be slicing.
    //**notation** object slicing is affected by 2 things is no virtual keyword and no pointer implementation.
    p_animal->speak();  // Calls Dog's speak() method through polymorphism.

    std::cout << "-------------------------\n";

    //Animal* animalPTR = &no_animal; this is error.

    // Cleanup
    delete no_animal;
    delete p_animal;

    return 0;
}

/* "Dog * no_animal = new Dog;": The pointer no_animal is of type Dog*, meaning it can only point to
objects of type Dog (or classes derived from Dog). Any method calls on no_animal will invoke
the Dog class's methods directly.

"Animal * p_animal = new Dog;": The pointer p_animal is of type Animal*, which means it can point to
objects of type Animal or any class derived from Animal, including Dog. This is a more general pointer. */