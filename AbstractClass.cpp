#include <iostream>


/* Interface: A special kind of abstract class that typically only contains pure virtual functions and
no data members or implemented functions. Interface cannot be used to create object.
Abstract Class: A class that contains at least one pure virtual function. in abstract there can be data members
but in interface is nothing. abstract class cannot be used to create object.

an interface is indeed a type of abstract class, but not all abstract classes are interfaces. */


// Interface (pure virtual class). interface is a class contains at least one pure virtual function
class Drawable {
public:
    virtual void draw() = 0; // Pure virtual function (virtual functions with no implementation) or abstrack function
};

// Abstract Class
class Shape {
protected:
    int x, y;  // Data members for position

public:
    Shape(int xPos, int yPos) : x(xPos), y(yPos) {}  // Constructor to initialize position

    virtual void area() = 0;  // Abstract method to be implemented by derived classes

    void move(int dx, int dy) {  // Concrete method to move the shape
        x += dx;
        y += dy;
    }

    int getX() const { return x; }  // Accessor method for x
    int getY() const { return y; }  // Accessor method for y
};

// Concrete Class that implements both the abstract class and the interface
class Circle : public Shape, public Drawable {
private:
    int radius;

public:
    Circle(int xPos, int yPos, int r) : Shape(xPos, yPos), radius(r) {}

    // Implementing the abstract method from Shape
    void area() override {
        std::cout << "Area of Circle: " << 3.14 * radius * radius << std::endl;
    }

    // Implementing the method from Drawable interface
    void draw() override {
        std::cout << "Drawing Circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

int main() {
    Circle circle(10, 20, 5);

    // Calling methods on Circle object
    circle.draw();  // From Drawable interface
    circle.area();  // From Shape abstract class
    circle.move(5, 10);  // From Shape abstract class
    circle.draw();  // Updated position after moving

    return 0;
}
