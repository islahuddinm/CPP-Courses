#include <string>
#ifndef CAR_H // stand for "if not defined (code file)"
#define CAR_H // stand for "define(code file)"

/* #ifndef, #define those are directive(yg menginstruksikan) check to ensure that the file's contents are
not included multiple times. This practice is known as an include guard. */

//reminder class and constructor name have to same
//car.h file is to declare the variable and fuctions we are going to use

class car
{
public:
	//below is attribute or member variable.
	std::string name; // first declaration.
	int acceleration;
	int speed;
	int brake;

	// Constructor name has to same with class name.
	car(); // constructor (constructor is allow creat an object) is a special member function of a class that is automatically called when an object of that class is created in main function.
	
	float get_handling(); //this fuction is to get access to handling variable in private by klick RMB - Quick actions and refactorings - Create definition of "get_handling"
	
	void set_handling(float modified_handling_value); //this fuction is to change value of "handling"

	void run();

	car(int power, int health); // another way to creat constructure.

private:
	float handling;
	float nitro;
};

class bike
{
public:
	bike();

	std::string name;
	int acceleration;
	int speed;
	int brake;
	int handling;
};

#endif // This marks the end of the conditional directive started by #ifndef.