#include <iostream>

// this is how to destruct automatically a destruction function when we create object kind of
// this "Animal * p_animal = new Dog;". so we have to give 'virtual' keyword every destruction function
// but if we create object like this "Dog * no_animal = new Dog;" we dont need to give 'virtual' keyword every destruction function

class Animal
{
public:
    Animal() = default;
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
    Feline() = default;
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
    Dog() = default;
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

   // Dog dog1;

    // this is not Polymorphism
    Dog * no_animal = new Dog; /* This is specific to the Dog class and does not provide the flexibility of
    handling other derived classes. The pointer can only point to Dog objects. */

    delete no_animal;
    
    // this is Polymorphism
    Animal * p_animal = new Dog; /* This allows the pointer to Animal to point to any derived class object
    (e.g., Dog, Cat, etc.). It provides flexibility because you can write functions that work with
    the base class (Animal) but accept any derived class object. */

    delete p_animal;
  
    return 0;
}