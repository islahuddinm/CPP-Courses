#include <iostream>
#include <string>

class cars {
public:
    cars() {
        name = "Spider 720";
        acceleration = 5;
        speed = 340;
        brake = 86;
        handling = 73;
        power = true;
    }

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
    myCar.behavior(); // Accessing the global object in main()
    return 0;
}
