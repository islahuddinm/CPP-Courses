#include <iostream>

/* Inheritance is a fundamental concept in OOP. Creating new classes based on existing classes,
inheriting their attributes and methods of existing classes while also allowing for customization and
extension.

or

Inheritance is a fundamental concept in object-oriented programming (OOP) that allows
one class (the derived class) to inherit properties and behavior from another class (the base class).
This enables code reuse and the creation of a hierarchy of classes.*/

// so if we create the derived class we will inherit properties, attribute and behavior from base class.




// this public is used to make 'abstrackEmployee' is public, its default is ptivate.
class employee { // derived class (or child class or sub class) is a class that is based on another class(called a base class or parent class). The derived class inherits attributes and behaviors (methods) from the base class and can also add new attributes and behaviors or override existing ones.
private: // when we change 'private' to be 'protected' it means they just allow a derived class(developer) to inherit/access atributes of base class(employee).
    std::string name;
    std::string company;
    int age;

public:
    std::string address;
    std::string hobby;

public:
    std::string getName() {
    // if we call 'name' in another class we keep have to write 'getName()' we cant write 'name'.
    // but in own class we can call by write 'name'.
        return this->name;        
    }
    std::string getCompany() {
    // if we call 'company' in another class we keep have to write 'getCompany()' we cant write 'company'. 
    // but in own class we can call by write 'company'.       
        return this->company;
    }
    int getAge() {
    // if we call 'age' in another class we keep have to write 'getAge()' we cant write 'age'. 
    // but in own class we can call by write 'age'. 
        return this->age;
    }
    
    // default constructor (a constructor with no arguments/parameter).
    //employee() = default; // constructor
    employee() { // this is default constructor. default constructor will call automatically if there is no constuctor
    /*if we call most 'special(derived class)', default constructors in other classes are going to be called in
    inheritance hierarchy even though we dont call them. it is going to call starting
    from most basic class(base class) going down to 'most special(derived class)' that we call.*/
        std::cout << "Default constructor Eployee" << '\n';
    }
    employee(std::string nameParam, std::string companyParam, int ageParam) { // constructor
        name = nameParam;
        company = companyParam;
        age = ageParam;
    }
    // this is how to "copy constructor". A copy constructor in C++ is a special constructor used to create
    // a new object as a copy of an existing object.
    employee(employee& source) // this "(employee& source)" is create object in parameter
    : name(source.name), company(source.company), age(source.age) /* this is another way initialize instead of in function body.*/
    {
        std::cout << "Costum copy constructor Employee" << '\n';
    }
    
    // this is a implementation in a class can be considered its behavior.
    void introduceYourself() {
        std::cout << "Name : " << name << '\n';
        std::cout << "Company : " << company << '\n';
        std::cout << "Age : " << age << '\n' << '\n';
    }    
};



/* this public is used to make 'employee' is public, its default is ptivate.
so we can access properties, attribute, method and behavior in main function.*/
class developer : public employee { // developer is a derived class of employee as base class/ parent class.
public:
    std::string favProgrammingLanguage;

    developer(std::string nameParam, std::string companyParam, int ageParam, std::string favProgrammingLanguageParam) 
    : employee(nameParam, companyParam, ageParam) { // constructor
        favProgrammingLanguage = favProgrammingLanguageParam;
    }

    // this is a implementation in a class can be considered its behavior.
    void fixBug() {
        std::cout << getName() << " fix bug using " << favProgrammingLanguage << '\n';
    }

// protected only can be accessed by derived class that inherit a base class has protected member.
// when we try to access through main function we cannot, only derived class inherit that can do.
protected: 
    int coba;
}; //int developer::coba = 10;



// in this class how to class engineer inherit private employee.
class engineer : private employee {
public:    
    //engineer() = default;
    // if we dont declare 'default constuctor' in base class(employee) we cant build default constructor in derived class.
    engineer() { // default constructor    
        std::cout << "Default constructor Engineer" << '\n';    
    }    
    // base class(employee) have to call to initialize in derived class.
    engineer(std::string nameParam, std::string companyParam, int ageParam, int yearsParam) 
    : employee(nameParam, companyParam, ageParam), years(yearsParam)/* this is another way initialize instead of in function body.*/ { // default constructor        
    }
    
    // this function allow to be printed out by using 'object name' in main function.
    // detail explanation about this function is in 'inheritance folder'.
    /* 'friend' keyword is used to give a non-member function access to private and protected members of
    a class. it means that a function that is not part of the class itself can still access the private and
    protected data of the class.*/
    friend std::ostream& operator<<(std::ostream& out, engineer& engineerParam) {
        out << "Name : " << engineerParam.employee::getName() << ", "
            << " Company : " << engineerParam.getCompany() << ", "
            << " Age : " << engineerParam.getAge() << ", "
            << " Years : " << engineerParam.years;
    return out; //  this implementation is returned in main fuction.
    }    

    // this is a implementation of a method (function) in a class can be considered its behavior.
    void work() {
        std::cout << employee::getName() << " is working " << '\n';
    }

    // this is implementation of 'introduceYourself()' in base class after access by using 'employee::introduceYourself;'
    void introduceYourselfFromEngineer() {
        introduceYourself();
    }

protected:    
    // this is how to get attributes in 'employee' even though 'engineer' inherit 'private employee'.
    // or resurrecting members back in scope.
    // 'using' allows you to use those names without having to prefix them with 'employee::'.
    using employee::address;
    using employee::hobby;
    employee::getName;
    using employee::getCompany;
    using employee::getAge;
    using employee::introduceYourself;
    
    int getYears() {
    // if we call 'years' in another class we keep have to write 'getYears()' we cant write 'years'.
    // but in own class we can call by write 'years'.
        return this->years;
    }
private:
    int years = 2024;
};



class civilEngineer : public engineer {
public:
    int contract = 0; // attribute.    
    
    //civilEngineer() = default;
    // if we dont declare 'default constuctor' in base class(engineer) we cant build default constructor in derived class.
    civilEngineer() { // default constructor.  
        std::cout << "Default constructor Civil Engineer" << '\n';    
    }
    // base class(engineer) have to call to initialize in derived class.  
    civilEngineer(std::string nameParam, std::string companyParam, int ageParam, int yearsParam, int contractParam) 
    : engineer(nameParam, companyParam, ageParam, yearsParam), contract(contractParam)/* this is another way initialize instead of in function body.*/ { // default constructor        
    }
    // this is how to copy constructor explicitly
    /*civilEngineer(civilEngineer& source)
    : engineer(source.getName(), source.getCompany(), source.getAge(), source.getYears()), contract(source.contract) 
    {
        std::cout << "Costum copy constructor Civil Engineer" << '\n';
    }*/
    // this is how to copy "constructor" in inheritance hierarchy. this is another way which is correct way.
    civilEngineer(civilEngineer& source) // this is "copy constructor" // this "(civilEngineer& source)" is create object in parameter
    : engineer(source), contract(source.contract) // 'engineer(source)' call all its data for '(civilEngineer& source)'
    {
        std::cout << "Costum copy constructor Civil Engineer" << '\n';
    }

    // this function allow to be printed out by using 'object name' in main function.
    // detail explanation about this function is in 'inheritance folder'.
    friend std::ostream& operator<<(std::ostream& out, civilEngineer& civilEngineerParam) {
        out << "Name : " << civilEngineerParam.engineer::getName() << ", "
            << " Company : " << civilEngineerParam.getCompany() << ", "
            << " Age : " << civilEngineerParam.getAge() << ", "
            << " Years : " << civilEngineerParam.getYears() << ", "
            << " Contract : " << civilEngineerParam.contract;
    return out; //  this implementation is returned in main fuction.
    }

    void work() {
        std::cout << engineer::getName() << " is working in " << getCompany() <<'\n';
    }
};



int main() {

    employee employee1("Mike", "Amazon", 26);    
    employee1.introduceYourself();    

    employee employee2("Sandrina", "Amazon", 32);    
    employee2.introduceYourself();    

    developer employee3("MI", "MI Company", 25, "C++");
    employee3.introduceYourself();   
    employee3.fixBug();
    //employee3.coba = 100; // we can not access this because it is protected.

    std::cout << '\n';

    engineer employee4("Engineer", "Starlink", 40, 2024);
    std::cout << employee4 << '\n'; // this is how to call "operator<<" function.
    employee4.introduceYourselfFromEngineer();
    employee4.work();
    
    std::cout << '\n';

    civilEngineer employee5("Civil Engineer", "Starlink", 40, 2025, 3);
    std::cout << employee5 << '\n';
    employee5.introduceYourselfFromEngineer();
    employee5.work();
    employee5.engineer::work(); // this is how to call 'work function' in engineer class by 'employee5 object'. so the function will be filled employee5's data.

    std::cout << '\n';       

    /* this is how to copy a 'object'(employee5) by storing "employee5" in "employee55"
    then we print "employee55" and then we would get same data result /print. */
    civilEngineer employee55 = employee5; // this is copy constructor
    std::cout << "Employe4 : " << employee55 << '\n'; // when we are printing this, we also can get employee's 'copy constructor' as well even though we dont call it.

    

    return 0;
}

/* we can copy object without having copy constructor you know.

Yes, in C++, you can indeed copy an object without explicitly defining a copy constructor.
However, there are important considerations to be aware of, particularly when dealing with
dynamically allocated memory or other resources.

What Happens When You Don't Define a Copy Constructor?
When you don't provide a custom copy constructor for a class, the C++ compiler generates
a default copy constructor for you. This default copy constructor performs a shallow copy of
the object's members.

Shallow Copy vs. Deep Copy:

Shallow Copy:
When we say a shallow copy is an "exact bitwise copy," it means that the new object is created by
copying each bit from the original object to the new one. Essentially, this means copying all the data
from one object to another in the simplest way possible. A shallow copy copies the values of the data members
(variables) from one object to another and the actual memory addresses are copied. Both objects point to
the same memory locations.

Deep Copy:
A deep copy, on the other hand, create new same object of another object and creates a new memory allocation
for the copied data. This ensures that the original and the copied objects are completely independent of
each other. To achieve a deep copy, you must define a custom copy constructor in class that handles the
copying of the data pointed to by any pointers in the class. */