#include <iostream>

/* this is how to make "Animal * p_animal = new Dog;" behavior like "Dog * no_animal = new Dog;" which
call automatically other destructors to achieve that we have to give "virtual keyword" at destruction function. */

/***notation*** dont call virtual(plymorphic) functions from constructor and destructor we cannot do 
dynamic binding over there. but we can do static binding over there (constructor and destructor). */

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
    
    /* this is Polymorphism(why i call "polymorphism"? because there are function use "virtual keyword" which
    the keyword is used to achieve polymorphism). */
    Animal * p_animal = new Dog;

    delete p_animal;
  
    return 0;
}