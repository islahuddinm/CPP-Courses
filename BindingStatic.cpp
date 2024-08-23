#include <iostream>

/*    
binding is link a function call with/to its function definition.
there are types of binding, that is static binding & dynamic binding.
Static Binding is binding occurs at Compile time.
Dynamic Binding is binding occurs at Runtime.

you know that dynamic and static binding are written at compile time. so what is differences?
dynamic binding is set up during compilation, but actual function to be called is decided during runtime.
static binding is set up and fixed during compilation. There is no further decision-making needed at runtime.
*/

class Shape
{
public:
    Shape(): Shape("NoDescription") {
    }    
    Shape(std::string_view description): m_description(description) {
        
    }    
    ~Shape(){
        
    }
    
    void draw( )const{
        std::cout << "Shape::draw() called for : " << m_description << std::endl;
    }
    
protected:
    std::string m_description;

};


class Ellipse : public Shape
{
public:
    Ellipse(): Ellipse(0.0,0.0,"NoDescription") {        
    }
    Ellipse(double x_radius, double y_radius, std::string_view description)
    : Shape(description), m_x_radius(x_radius), m_y_radius(y_radius) {
        
    }
    ~Ellipse(){
        
    }

    void draw( )const{
        std::cout << "Ellipse::draw() called for : " << m_description << std::endl;
    }
	
//private : 
    double m_x_radius;
    double m_y_radius;
};


class Oval : public Ellipse
{
public:
    Oval(): Oval(0.0,0.0,"NoDescription") {        
    }
    Oval(double x_radius, double y_radius, std::string_view description):
    Ellipse(x_radius, y_radius, description) {

    }
    ~Oval() {

    }

    void draw( )const{
        std::cout << "Oval::draw() called for : " << m_description << std::endl;
    }

};


int main(){

    Shape shape1("Shape1");
    Ellipse ellipse1(1, 1, "Ellipse1");
	Oval oval1(2, 2, "Oval1");

    shape1.draw();
    ellipse1.draw();
    oval1.draw();

    std::cout << "\n";
    std::cout << "Calling methods through pointers : static binding\n";

    Shape* shapePtr = &shape1;
    shapePtr->draw(); // this is static binding, static binding will call "Shape::draw()"

    // this gets "slicing"
    shapePtr = &ellipse1;
    shapePtr->draw(); /* this is static binding, this static binding will call "Shape::draw()" even though
    i create "ellipse1 object" at "Ellipse class". but i want to call "Ellipse::draw()", to call
    this "Ellipse::draw()" we have to use dynamic binding, this time is not dynamic binding.
    to use dynamic binding, check at "BindingDynamic.cpp". */

    // this gets "slicing"
    shapePtr = &oval1;
    shapePtr->draw(); /* this is static binding, this static binding will call "Shape::draw()" even though
    i create "oval1 object" at "Oval class". but i want to call "Oval::draw()", to call
    this "Oval::draw()" we have to use dynamic binding, this time is not dynamic binding.
    to use dynamic binding, check at "BindingDynamic.cpp". */
   
    return 0;
}

/* Static Binding: The method call is determined at compile time, used for non-virtual functions, and is faster.
Static Binding: Used in non-polymorphic scenarios, such as calling non-virtual functions or method overloading.

Dynamic Binding: The method call is determined at runtime, used for virtual functions, and supports
polymorphism, though with a slight performance cost.
Dynamic Binding: Used in polymorphic scenarios, especially when working with virtual functions and inheritance. */
