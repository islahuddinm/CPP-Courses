#include <iostream>
#include <string>

class Address {
public:
    std::string street;
    std::string city;
    int zipCode;

    Address(std::string str, std::string cty, int zip) : street(str), city(cty), zipCode(zip) {}
};

class Person {
public:
    std::string name;
    Address address; // Creating an object of Address class inside Person class

    Person(std::string n, Address addr) : name(n), address(addr) {}
    
    void display() {
        std::cout << "Name: " << name << "\n"
                  << "Address: " << address.street << ", " << address.city << ", " << address.zipCode << "\n";
    }
};

int main() {
    Address addr("123 Main St", "Anytown", 12345);
    Person person("John Doe", addr);

    person.display();

    return 0;
}
