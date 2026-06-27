#include <iostream>

/*

// 'this' is a keyword points directly to the specific object instance that is currently executing that function.
// '->' symbol is called the Arrow Operator (or Class Member Access Operator), and it is used to access the variables or methods of a class.
// Pointer uses '->'(arrow access symbol).
// Non Pointer uses '.'(dot access symbol).

When you use this, you are referring to the current object instance. This is particularly useful
when you have a member variable with the same name as a parameter in a member function, and
you need to differentiate between the two.

"->": The arrow operator, which is used in C++ to access a member variable or function through a pointer

*/

void verifyPlayer(Player* p); // External function

class Player {
public:
    void joinMatch() {
        verifyPlayer(this); // Passes a pointer to itself (Passing the Object to External Function)
    }
};

class Scoreboard {
private:
    int score = 0;

public:
    Scoreboard& addPoints(int points) {
        score += points;
        return *this; // Returns reference to the current instance (Enabling Method Chaining)
    }

    void display() { std::cout << score; }
};

class Player {
private:
    int health;
    // When a function parameter shares the exact same name as a class data member, the parameter name hides the class member.
    // You use this-> to explicitly tell the compiler to target the class member.
public:
    Player(int health) {
        // 'this->health' refers to the private variable.
        // 'health' refers to the constructor parameter.
        this->health = health; 
    }
};


int main() {

    // Usage:
    Scoreboard game;
    game.addPoints(10).addPoints(5).display(); // Outputs 15


    return 0;
}