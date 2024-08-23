#include <iostream>
#include <string>
#include <memory>  // Required for std::shared_ptr and std::make_shared

class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing Shape" << std::endl;
    }

    // this is function overloading (Same function name with different parameters (within the same scope).)
    virtual void draw( std::string def) const {
        std::string definition = def;
        std::cout << "Definition Shape: " << definition << std::endl;
    }
};

class Circle : public Shape {
    float radius;
    std::string name;
public:
    Circle(float r, std::string n) : radius(r), name(n) {}
    /* void draw() const override {
        std::cout << "Drawing Circle: " << name << " with radius " << radius << std::endl;
    } */
};

class Oval : public Shape {
    float radius1, radius2;
    std::string name;
public:
    Oval(float r1, float r2, std::string n) : radius1(r1), radius2(r2), name(n) {}
    void draw() const override {
        std::cout << "Drawing Oval: " << name << " with radii " << radius1 << " and " << radius2 << std::endl;
    }
};

int main() {
    Shape shape1;
    Oval oval1(13.3, 1.2, "Oval1");
    Circle circle1(11.2, "circle2");

    circle1.draw();
    circle1.draw("overload"); // we cannot access "overload function". how to access the function?
    // to access the function we have to hide "virtual" draw() function in "Circle class" or add "overide" 'draw(std::string def)' function.
    // check at "PolymorphismOverload2.cpp" "PolymorphismOverload3.cpp"
    
    return 0;
}