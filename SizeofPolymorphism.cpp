#include <iostream>

/* Polymorphism(many forms) or concpept or method in C++ allows us to reuse code by creating one function
that's usable for multiple uses in different scenarios. In simple terms, polymorphism enables one interface to
be used for a general class of actions. There are two main types of polymorphism:
- Compile-Time Polymorphism (Static Binding):
Achieved through method overloading and operator overloading.
example, check at "BindingStatic.cpp" and "BindingDynamic.cpp"
- Run-Time Polymorphism (Dynamic Binding):
Achieved through inheritance and function overriding.
example, check at "BindingStatic.cpp" and "BindingDynamic.cpp"


Inheritance is a fundamental concept in OOP. Creating new classes based on existing classes,
inheriting their attributes and methods of existing classes while also allowing for customization and
extension.

or

Inheritance is a fundamental concept in object-oriented programming (OOP) that allows
one class (the derived class) to inherit properties and behavior from another class (the base class).
This enables code reuse and the creation of a hierarchy of classes.*/

// so if we create the derived class we will inherit properties, attribute and behavior from base class.

/* virtual keyword is used to a base class's member function that you can redefine in
a derived class to achieve polymorphism. you can use a pointer or reference to call the virtual function in
base class and it will automatically execute its actual function(you have redifined function) in
the derived class.FOR EXAMPLE IN MAIN FUNCTION BELOW.*/

/* Interface: A special kind of abstract class that typically only contains pure virtual functions and
no data members or implemented functions.
Abstract Class: A class that contains at least one pure virtual function.
an interface is indeed a type of abstract class, but not all abstract classes are interfaces. */


// abstract class / interface is a class contains at least one pure virtual function
class abstrackEmployee { // base/parent class.
    virtual void askForPromotion() = 0; // Pure virtual function (virtual functions with no implementation) or abstrack function
};


// this public is used to enable to access 'abstrackEmployee' class. if there dont declare, its default is ptivate.
class employee : public abstrackEmployee { // derived class (or child class or sub class) is a class that is based on another class(called a base class or parent class). The derived class inherits attributes and behaviors (methods) from the base class and can also add new attributes and behaviors or override existing ones.
private: // when we change 'private' to be 'protected' it means they just allow a derived class(developer) to inherit/access atributes of base class(employee).
    std::string name;
    std::string company;
    int age;
    char blood;

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
    int getBlood() {  
        return this->blood;
    }

    // default constructor (a constructor with no arguments).
    employee() = default; // constructor
    employee(std::string nameParam, std::string companyParam, int ageParam) { // constructor
        name = nameParam;
        company = companyParam;
        age = ageParam;
    }

    virtual void working() { // this is virtual function ///////////////////////////////////////////////
        std::cout << name << " is working in " << '\n';
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
    void working() {
        std::cout << getName() << " fix bug using " << favProgrammingLanguage << '\n';
    }
};

class teacher : public employee { 
public:
    std::string subject;

    teacher(std::string nameParam, std::string companyParam, int ageParam, std::string subjectParam) : employee(nameParam, companyParam, ageParam) { // constructor
        subject = subjectParam;
    }
    
    void working() {
        std::cout << getName() << " is teaching " << subject << '\n';
    }
};



void printMethod(employee *E);
int main() {

    employee employee1("Mike", "Amazon", 26);
    employee1.askForPromotion();   

    teacher employee2("Sandrina", "Amazon", 32, "Math");
    employee2.askForPromotion();    

    developer employee3("MI", "MI Company", 25, "C++");   
    employee3.askForPromotion();

    std::cout << '\n';

    employee2.working();
    employee3.working();
   
    std::cout << '\n'; //////////////////////////////////////////////////////////////////////////////////////

    // ***notation*** if we comment "virtual" keyword on function we could get different size
    std::cout << "//////////////////////////////////////// OBJECT SIZES with VIRTUAL(size + 8)" << '\n';
    std::cout << "Size of (employee1) : " << sizeof(employee1) << " bytes" << '\n';  // size of 'employee1' is 80
    std::cout << "Size of (employee2) : " << sizeof(employee2) << " bytes" << '\n'; // size of 'employee2' and 'employee1'. compiler will count 2 object beause 'employee2 'inherit 'employee1'.
    std::cout << "Size of (employee3) : " << sizeof(employee3) << " bytes" << '\n'; // size of 'employee3' and 'employee1'. compiler will count 2 object beause 'employee3 'inherit 'employee1'.
    std::cout << "//////////////////////////////////////// CLASS SIZES with VIRTUAL(size + 8)" << '\n';
    std::cout << "Size of (employee) : " << sizeof(employee) << " bytes" << '\n';
    std::cout << "Size of (developer) : " << sizeof(developer) << " bytes" << '\n';
    std::cout << "Size of (teacher) : " << sizeof(teacher) << " bytes" << '\n';

    // this would get "slicing". it means "employee" class only be able to hold its capacity, wherease
    // employee3 object of "developer" class has bigger size than "employee" class. so it would get slicing.
    // so how to avoid "slicing"? give "virtual" keyword at functions or other attributes. check at "BindingStatic.cpp" and "BindingDynamic.cpp" 
    employee employee = employee3;
    std::cout << "//////////////////////////////////////// OBJECT SIZES with VIRTUAL(size + 8)" << '\n';
    std::cout << "Size of (employee3) ONLY : " << sizeof(employee) << " bytes" << '\n';

    ///**notation** object slicing is affected by 2 things is no virtual keyword and no pointer implementation.
    /* To avoid both slicing and incorrect function calls, you should:
    - Use pointers or references to base class types when working with derived objects.
    - Mark functions as virtual in the base class when they need to be overridden in derived classes. */
    
    return 0;
}

void printMethod(employee *E) {
    E->working();
}