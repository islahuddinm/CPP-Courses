#include <iostream>

// this is how default constructor behaves. constructor and destructor are called in order.

/***notation*** dont call virtual(plymorphic) functions from constructor and destructor we cannot do 
dynamic binding over there. but we can do static binding over there (constructor and destructor). */

class Animal
{
public:
    Animal() {std::cout << "Default Constructor Animal\n";}
    Animal(std::string_view description)
    : m_description(description) {
    }
    virtual ~Animal() {
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
    Feline() {std::cout << "Default Constructor Feline\n";}
    Feline(std::string_view fur_style, std::string_view description)
    : Animal(description) , m_fur_style(fur_style) {
    }
    virtual ~Feline() {
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
    Dog() {std::cout << "Default Constructor Dog\n";}
    Dog(std::string_view fur_style, std::string_view description)
    : Feline(fur_style,description) {
    }
    virtual ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
    }
        
    virtual void bark() const{
        std::cout << "Dog::bark called : Woof!" << std::endl;
    }
};

int main(){

    /* when we create object without parameter of animal class / base class, default constructor in
    animal class would be called automatically. */
    Animal* dog1 = new Animal; // this is how to create object on heap memory

    std::cout << "------------------------- 1" << std::endl;

    /* when we create object without parameter of dog class / child/derived class, default constructor in
    animal, feline, dog class would be called automatically even though we dont call all of it. */
    Animal* dog2 = new Dog;

    std::cout << "------------------------- 2" << std::endl;

    Animal dog3; // this is how to create object on stack memory

    std::cout << "------------------------- 3" << std::endl;

    Dog dog4;

    std::cout << "------------------------- 4" << std::endl;

    Dog* dog5 = new Dog;

    std::cout << "------------------------- 5" << std::endl;

    /* what does difference create object on heap and stack memory?
    when we create object on stack memory, destructor function will be called automatically while
    heap memory will not be called automatically. */

    return 0;
}