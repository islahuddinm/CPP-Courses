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

int main() {
    // Initializing the member variables of the myCar object
    myCar.name = "Spider 720";
    myCar.acceleration = 5;
    myCar.speed = 340;
    myCar.brake = 86;
    myCar.handling = 73;

    myCar.behavior(); // Accessing the global object in main()
    return 0;
}
