#include <iostream>

/* Inheritance is a fundamental concept in OOP. Creating new classes based on existing classes,
inheriting their attributes and methods of existing classes while also allowing for customization and
extension.

or

Inheritance is a fundamental concept in object-oriented programming (OOP) that allows
one class (the derived class) to inherit properties and behavior from another class (the base class).
This enables code reuse and the creation of a hierarchy of classes.*/

// so if we create the derived class we will inherit properties, attribute and behavior from base class.


class abstrackEmployee { // base/parent class.
    virtual void askForPromotion() = 0; // Pure virtual function or abstrack function.
};


// this public is used to make 'abstrackEmployee' is public, its default is ptivate.
class employee : public/*public is base access specifier*/ abstrackEmployee { // derived class (or child class or sub class) is a class that is based on another class(called a base class or parent class). The derived class inherits attributes and behaviors (methods) from the base class and can also add new attributes and behaviors or override existing ones.
private: // when we change 'private' to be 'protected' it means they just allow a derived class(developer) to inherit/access atributes of base class(employee).
    std::string name;
    std::string company;
    int age;

public:
    std::string getName() {
        return this->name;        
    }
    std::string getCompany() {        
        return this->company;
    }
    int getAge() {  
        return this->age;
    }

    /* Constructor/ Default Constructor (constructor is allow creat an object) is a special member function of
    a class that is automatically called when an object of that class is created in main function. but
    keep in mind there is also called as a Custom Constructor which constructor has parameters. its behavior of
    custom constructor is not called automatically like the default constructor. */
    // default constructor (a constructor with no arguments).
    employee() = default; // constructor
    employee(std::string nameParam, std::string companyParam, int ageParam) { // custom constructor
        name = nameParam;
        company = companyParam;
        age = ageParam;
    }
    
    // this is a implementation in a class can be considered its behavior.
    void introduceYourself() {
        std::cout << "Name : " << name << '\n';
        std::cout << "Company : " << company << '\n';
        std::cout << "Age : " << age << '\n';
    }

    // this is a implementation of a method (function) in a class can be considered its behavior.
    void askForPromotion() {
        if (age > 30) {
            std::cout << name << " get promoted!" << '\n';
        }
        else {
            std::cout << name << ", no promotion for you!" << '\n';
        }
    }
};


/* this public is used to make 'employee' is public, its default is ptivate.
so we can access properties, attribute, method and behavior in main function.*/
class developer : public employee { // developer is a derived class of employee as base class/ parent class.
public:
    std::string favProgrammingLanguage;

    developer(std::string nameParam, std::string companyParam, int ageParam, std::string favProgrammingLanguageParam) : employee(nameParam, companyParam, ageParam) { // constructor
        favProgrammingLanguage = favProgrammingLanguageParam;
    }

    // this is a implementation in a class can be considered its behavior.
    void fixBug() {
        std::cout << getName() << " fix bug using " << favProgrammingLanguage << '\n';
    }
};

int main() {

    employee employee1("Mike", "Amazon", 26);
    employee1.askForPromotion();   

    employee employee2("Sandrina", "Amazon", 32);
    employee2.askForPromotion();    

    developer employee3("MI", "MI Company", 25, "C++");
    employee3.fixBug();
    employee3.askForPromotion();

    return 0;
}