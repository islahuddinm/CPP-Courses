#include <iostream>
#include <string>

void me() {
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

    cars myCar;
    myCar.name = "McLaren";
    myCar.acceleration = 10;
    myCar.speed = 100;
    myCar.brake = 5;
    myCar.handling = 8;
    myCar.power = true;

    myCar.behavior();
}

int main() {
    me();
    return 0;
}


/*
how to create object in main fuction by using this class which is inside function?

To create an object of a class that is defined inside a function, you need to define the class outside of
the function so that it is visible to other parts of your program.
*/