#include <iostream>

// this is how destructor behaves.  constructor and destructor are called in order.

/***notation*** dont call virtual(plymorphic) functions from constructor and destructor we cannot do 
dynamic binding over there. but we can do static binding over there (constructor and destructor). */

class Animal
{
public:
    Animal() {std::cout << "Animal::constructor\n";}
    Animal(std::string_view description)
    : m_description(description) {
    }
    ~Animal() {
        std::cout << "Animal destructor called" << std::endl;
    }
    
    virtual void breathe()const{
        std::cout << "Animal::breathe called for : " << m_description << std::endl;
    }
    
protected: 
    std::string m_description;
};

class Feline : public Animal
{
public:
    Feline() = default;
    Feline(std::string_view fur_style, std::string_view description)
    : Animal(description) , m_fur_style(fur_style) {
    }
    ~Feline() {
        std::cout << "Feline destructor called" << std::endl;
    }
        
    virtual void run() const{
        std::cout << "Feline " << m_description << " is running" << std::endl;
    }
    std::string m_fur_style;
};

class Dog : public Feline
{
public:
    Dog() {std::cout << "Dog::constructor\n";}
    Dog(std::string_view fur_style, std::string_view description)
    : Feline(fur_style,description) {
    }
    ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
    }
        
    virtual void bark() const{
        std::cout << "Dog::bark called : Woof!" << std::endl;
    }
};

int main(){

   // Dog dog1;

    Dog * no_animal = new Dog;

    delete no_animal;

    std::cout << "------------------------- 1" << std::endl;
    
    // creates a single object of "Dog" type, but you are storing its address in a pointer of type Animal *.
    Animal * p_animal = new Dog;

    delete p_animal;

    /* what does difference create object "Dog * no_animal = new Dog;" between "Animal * p_animal = new Dog;" ?
    when we create object like this "Dog * no_animal = new Dog;" when we delete that/ object of dog class,
    we would call destructor functions of dog, feline, animal class. but if we create object like
    this "Animal * p_animal = new Dog;" when we delete that/ object, we would only call decstructor function of
    dog class.
    
    the question is when we create object like this "Animal * p_animal = new Dog;", how to make its behavior
    like "Dog * no_animal = new Dog;" which call automatically other destructors, check at "Destructor4.cpp". */
  
    return 0;
}