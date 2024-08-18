#include <iostream>
#include <string>
#include <memory>  // Required for std::shared_ptr and std::make_shared

class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing Shape" << std::endl;
    }
};

class Circle : public Shape {
    float radius;
    std::string name;
public:
    Circle(float r, std::string n) : radius(r), name(n) {}
    void draw() const override {
        std::cout << "Drawing Circle: " << name << " with radius " << radius << std::endl;
    }
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
    Circle circle1(7.2, "circle1");
    Oval oval1(13.3, 1.2, "Oval1");
    Circle circle2(11.2, "circle2");
    Oval oval2(31.3, 15.2, "Oval2");
    Circle circle3(12.2, "circle3");
    Oval oval3(53.3, 9.2, "Oval3");

    /* 
    // Incorrect: Array of Shape objects, leading to object slicing
    Shape shapes1[] = {circle1, oval1, circle2, oval2, circle3, oval3};

    // Attempt to draw each shape (but it won't work as intended due to object slicing). "as intended"(sebagaimana yg dimaksud(adverb)), "due to"(disebabkan oleh(preposition))
    for (Shape s : shapes1) {
        std::cout << "Inside array sizeof(shape) : " << sizeof(s) << std::endl;
        //s.draw();  // This will only call Shape's draw(), not the derived classes' draw()
        Shape *shapePTR = &s;
        shapePTR->draw();
        std::cout << std::endl;
    } 
    */

    // this is correct way. we would not get data slicing of each object because we use pointer.
    Shape *shapes1[] = {&circle1, &oval1, &circle2, &oval2, &circle3, &oval3};
    
    for (Shape *s : shapes1) {
        std::cout << "Inside array sizeof(shape) : " << sizeof(*s) << std::endl;
        s->draw();
        std::cout << std::endl;
    }

    std::cout << "---------------------------------------------\n";

    // this is also correct way below
    // Using std::shared_ptr with std::make_shared to create and manage objects
    std::shared_ptr<Shape> shapes4[] = {
        std::make_shared<Circle>(12.2, "Circle4"),
        std::make_shared<Oval>(10.0, 20.0, "Oval4")
    };

    // Draw each shape using polymorphism
    for (const auto& s : shapes4) {
        s->draw();  // Correctly calls the derived class's draw() method
    }

    return 0;
}
