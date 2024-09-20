#include <iostream>
#include <string>
using namespace std;

// this is concept of separating calss files.

class Cars {
public: // it means only can use/access in another function.
    // member variable is variables that are associated with a specific instance of a class (object) and hold the state or data for that object or frist declaration.
    string make;
    string model;
    int year;

private: // it means only can use/access in local.
    // member variable is variables that are associated with a specific instance of a class (object) and hold the state or data for that object or frist declaration.
    double price;
    double price2;

public:
    /* Constructor/ Default Constructor (constructor is allow creat an object) is a special member function of
    a class that is automatically called when an object of that class is created in main function. but
    keep in mind there is also called as a Custom Constructor which constructor has parameters. its behavior of
    custom constructor is not called automatically like the default constructor. */
    // Constructor name has to same with class name.
    Cars() { // this is default constructor.
        // access member variable or attribute.
        make = "Mclarent";
        model = "720 Spider";
        year = 2023;
        price = 1000;
        //price2 = 2000;

        std::cout << "default called" << '\n';
    }

    void run() {
        price2 = 2000; // we can still access even though it is private because it is in same class.
    }

    // Getter function is an accessor method that is used to retrieve the value of a private.
    double getPrice() {
        return this->price; // actually without "this->" in c++23 we can keep access member variable.
        /* this-> notation in C++ is used within a class's member functions to explicitly access
        the members of the current object (the object on which the member function is being called).*/
    }

    // Setter function is a method that is used to modify the value of a private or protected data member of a class.
    void setPrice(double newPrice) {
        price = newPrice;
    }

    // another way to creat constructure.
    Cars(std::string a, std::string b, int c, double d) { // this is Parameterized Constructor
        // access member variable or attribute.
        make = a;
        model = b;
        year = c;
        price = d;
    }

    // default constructor. it is to create empty constrauctor.
    /* Cars() {
        std::cout << "Default constructor is callsed\n";
    } */

};

int main() {
    // Creating an object of the Cars class and also to call atributes.
    Cars myCar = Cars(); // Cars() is constructure. //here "myCar" is object name/ a object. "cars" is class to access inside class
    
    cout << "Make: " << myCar.make << endl;
    cout << "Model: " << myCar.model << endl;
    cout << "Year: " << myCar.year << endl;
    cout << "Price: $" << myCar.getPrice() << endl;
    myCar.setPrice(2000);    
    cout << "Price: $" << myCar.getPrice() << endl;
    cout << endl;
    
    // Another way to creating an object of the Cars class and also to call atributes.
    Cars mclarent = Cars("Mclarent", "720", 2024, 20000);

    cout << "Make: " << mclarent.make << endl;
    cout << "Model: " << mclarent.model << endl;
    cout << "Year: " << mclarent.year << endl;
    cout << "Price: $" << mclarent.getPrice() << endl;
    cout << endl;

    // this is creating object by Using the default constructor
    Cars bugg;

    // this is creating object by Using the parameterized constructor
    // we can do like this instead of 'Cars mclarent = Cars("Bugatti", "720", 2024, 20000);'.
    Cars bugatti ("Bugatti", "Ceiron", 2024, 20000);

    cout << "Make: " << bugatti.make << endl;
    cout << "Model: " << bugatti.model << endl;
    cout << "Year: " << bugatti.year << endl;
    cout << "Price: $" << bugatti.getPrice() << endl;
    cout << endl;

    Cars bugatti2("Bugatti", "Ceiron", 2024, 20000);

    cout << "Make: " << bugatti2.make << endl;
    cout << "Model: " << bugatti2.model << endl;
    cout << "Year: " << bugatti2.year << endl;
    cout << "Price: $" << bugatti2.getPrice() << endl;
    cout << endl;

    // this is how to call defautl constructor.
    //Cars ferarri;

    return 0;
}