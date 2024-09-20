#include <iostream>

// Class for MyBall (the result of throwBall)
class MyBall {
public:
    std::string state;

    // Constructor
    MyBall(const std::string& state) : state(state) {}

    // Display state of the ball
    void display() const {
        std::cout << "Ball is " << state << "." << std::endl;
    }
};

// Class for BallObject (the object that throws the ball)
class BallObject {
public:
    // Method to throw the ball, returns a MyBall object
    MyBall throwBall() const {
        return MyBall("thrown"); // Returning a MyBall object with state "thrown"
    }
};

// Function to simulate getting a pointer to a BallObject
BallObject* GetBallObject() {
    return new BallObject();
}

BallObject* GetBallObject2() {    
    
    BallObject* ballObj;
    return ballObj;
}

int main() {
    // Get a pointer to a BallObject
    BallObject* ballObject = GetBallObject();

    // Call throwBall() on the BallObject and store the result in MyBall
    MyBall myBall = ballObject->throwBall();
    MyBall myBall2 = GetBallObject2()->throwBall();

    // Display the state of myBall
    myBall.display();

    // Clean up the allocated memory
    delete ballObject;

    return 0;
}
