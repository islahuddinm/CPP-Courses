#include <iostream>

/* "blueprint" refers to the class definition itself. It's called a "blueprint" because
it specifies how objects of that class should be created and what properties and behaviors
they should have, similar to how a blueprint for a building specifies its design and construction details.
Once you have a blueprint (class), you can create multiple instances (objects) based on that blueprint,
each with its own unique set of data and behaviors.*/

//class(keyword) is a user-defined data type that serves(dipakai) as a blueprint for creating objects. class refer to template and than object represent instance of the class (example : car can be class's name and then object can be bmw, bugatti, etc.)
//car class has some attribute (name, prize, speed, color, etc.) and has some behaviour (drive, brake, change color, etc.) as well
//class is used as a template or blueprint for creating objects.

int topSpeed;

class cars {
    
public : // it means only can use/access in another function.
    /* member function are used to implement the behavior of the class and can access the
    class's member variables and other member functions.*/
    void behavior() {         
        std::cout << "Mclaren is running" << '\n';
    }

    int behavior2() {

        return topSpeed;
        return speed + power;
    }

public:
    // member variable is variables that are associated with a specific instance of a class (object) and hold the state or data for that object or frist declaration.
    std::string name; // you can use "std::string name;" instead of "std::string name = 0;"
    int acceleration;
    int speed;
    int brake;
    int handling;
    bool power;

};

//cars::acceleration = 100; error
//acceleration = 100; error

int main() {
    // this is how to create object. or how to call default constructor.
    cars trial{"m", 1, 2, 3, 4}; //here "Mclaren" is object name/ a object that already made. "cars" is a class.
    
    std::cout << "Name : " << trial.name << '\n';
    std::cout << "Acceleration : " << trial.acceleration << '\n';
    std::cout << "Speed : " << trial.speed << '\n';
    std::cout << "Brake : " << trial.brake << '\n';
    std::cout << "Handling : " << trial.handling << '\n';

    cars mclaren;

    // access member variable.
    mclaren.name = "Spider 720"; //here "name" is member variable/ attribute.
    mclaren.acceleration = 5;
    mclaren.speed = 340;
    mclaren.brake = 86;
    mclaren.handling = 73;

    // we can access something like this
    cars mclaren2 = {
        .name = "Spider2 720",
        .acceleration = 5,
        .speed = 340,
        .brake = 86,
        .handling = 73,
        .power = false
    };

    // also we can access something like this
    class cars mclaren3 = {
        .name = "Spider3 720",
        .acceleration = 5,
        .speed = 340,
        .brake = 86,
        .handling = 73,
        .power = false
    };

    mclaren.behavior();
    std::cout << '\n';

    std::cout << "Name : " << mclaren.name << '\n';
    std::cout << "Acceleration : " << mclaren.acceleration << '\n';
    std::cout << "Speed : " << mclaren.speed << '\n';
    std::cout << "Brake : " << mclaren.brake << '\n';
    std::cout << "Handling : " << mclaren.handling << '\n' << '\n';

    std::cout << "Name : " << mclaren2.name << '\n';
    std::cout << "Acceleration : " << mclaren2.acceleration << '\n';
    std::cout << "Speed : " << mclaren2.speed << '\n';
    std::cout << "Brake : " << mclaren2.brake << '\n';
    std::cout << "Handling : " << mclaren2.handling << '\n';

    return 0;
}