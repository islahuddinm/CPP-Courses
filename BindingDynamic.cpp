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
    
    virtual void draw( )const{
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

    void xray() {
        std::cout << "xray\n";
    }

};


void drawShape(Shape* s) {
    s->draw();
}


int main(){

    Shape shape1("Shape1");
    Ellipse ellipse1(1, 1, "Ellipse1");
	Oval oval1(2, 2, "Oval1");

    std::cout << "Calling methods through pointers : dynamic binding\n";

    Shape* shapePtr = &shape1;
    shapePtr->draw(); // this is dynamic binding.

    shapePtr = &ellipse1;
    shapePtr->draw(); /* this is dynamic binding. why do i call dynamic binding? because now i be able to
    call "Ellipse::draw()". how come i do that, before at "BindingStatic.cpp" i cannot call "Ellipse::draw()"?
    to solve the problem i give "virtual" keyword at "draw()" function in base class. */

    shapePtr = &oval1;
    shapePtr->draw(); /* this is dynamic binding. why do i call dynamic binding? because now i be able to
    call "Oval::draw()". how come i do that, before at "BindingStatic.cpp" i cannot call "Oval::draw()"?
    to solve the problem i give "virtual" keyword at "draw()" function in base class. */
    shapePtr->xray();// this function call would be error because "xray()" is not virtual(polymorphic) function.
    // it means there is no "xray()" function in base class.

    Shape& shapeRef = oval1;
    shapeRef.draw();

    std::cout << "-------------------------------------------------------------\n";
    std::cout << "Calling methods through pointers : dynamic binding with array\n";

    /* SO WHAT IS DYNAMIC BINDING FOR? 
    well, dynamic binding enables to print many object's functions at the same time through "array".
    we can see below how it looks like. */

    Shape* objCollections[] = {&shape1, &ellipse1, &oval1};

    for(Shape* ref : objCollections) {
        ref->draw();
    }

    std::cout << "-------------------------------------------------------------\n";
    std::cout << "dynamic binding with function\n";

    drawShape(&shape1);
    drawShape(&ellipse1);
   
    return 0;
}

/* Static Binding: The method call is determined at compile time, used for non-virtual functions, and is faster.
Static Binding: Used in non-polymorphic scenarios, such as calling non-virtual functions or method overloading.

Dynamic Binding: The method call is determined at runtime, used for virtual functions, and supports
polymorphism, though with a slight performance cost.
Dynamic Binding: Used in polymorphic scenarios, especially when working with virtual functions and inheritance. */