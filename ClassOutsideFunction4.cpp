#include <iostream>
#include <string>

// 'cars::name = "Spider 720";' this is how to access inside class
// 'myCar.name = "Spider 720";' this is how to access inside class from main function

class cars {
public:
    void behavior() {
        std::cout << "Mclaren is running" << '\n';
    }

public:
    static std::string name;
    static int acceleration;
    static int speed;
    static int brake;
    static int handling;
    static bool power;
};

// Initializing static member variables of the cars class
std::string cars::name = "Spider 720";
int cars::acceleration = 5;
int cars::speed = 340;
int cars::brake = 86;
int cars::handling = 73;
bool cars::power = true;

// Creating a global object of the cars class
cars myCar;

int main() {
    myCar.behavior(); // Accessing the global object in main()
    return 0;
}



/*
//////////////////////////// i dont know this cannot work //////////////////////////////

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

// Initializing the member variables of the global object
std::string cars::name = "Spider 720";
int cars::acceleration = 5;
int cars::speed = 340;
int cars::brake = 86;
int cars::handling = 73;
bool cars::power = true;

int main() {
    myCar.behavior(); // Accessing the global object in main()
    return 0;
}

*/