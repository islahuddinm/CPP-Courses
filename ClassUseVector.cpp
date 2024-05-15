#include <iostream>
#include <vector>

class MyClass {
public:
    // Member function to add an element to the vector
    void addElement(int element) {
        myVector.push_back(element);
    }

    // Member function to print all elements in the vector
    void printElements() {
        for (int i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << " ";
        }
        std::cout << std::endl;
    }

private:
// we can initialize private variable through function and cannot initialize from public without function to private variable
    std::vector<int> myVector;  // Vector as a member of the class
};

int main() {
    MyClass obj;
    obj.addElement(10);
    obj.addElement(20);
    obj.addElement(30);

    obj.printElements();  // Output: 10 20 30

    return 0;
}
