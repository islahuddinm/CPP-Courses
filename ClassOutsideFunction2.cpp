#include <iostream>
#include <string>

// Step 1: Define the class
class Car {
public:
    Car(std::string name, int acceleration, int speed, int brake, int handling, bool power) 
        : name(name), acceleration(acceleration), speed(speed), brake(brake), handling(handling), power(power) {}

    void behavior() {
        std::cout << name << " is running" << '\n';
    }

public:
    std::string name;
    int acceleration;
    int speed;
    int brake;
    int handling;
    bool power;
};

// Step 2: Declare the global object and initialize it
Car myCar("Spider 720", 5, 340, 86, 73, true);

int main() {
    // You can now use the global object
    myCar.behavior(); // Output: Spider 720 is running

    return 0;
}

/*
//////// we cannot directly assign values to member variables of a class outside of a function. something like this ////////

#include <iostream>
#include <string>

class cars {
public:
    void behavior() {
        std::cout << "Mclaren is running" << '\n';
    }

public:
    std::string name;
    int acceleration;
    int speed;
    int brake;
    int handling;
    bool power;
};

// Creating a global object of the cars class
cars myCar;

// access member variable.
myCar.name = "Spider 720"; //here "name" is member variable/ attribute.
myCar.acceleration = 5;
myCar.speed = 340;
myCar.brake = 86;
myCar.handling = 73;

int main() {
    myCar.behavior(); // Accessing the global object in main()
    return 0;
}

*/
