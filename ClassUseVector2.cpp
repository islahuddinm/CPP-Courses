#include <iostream>
#include <vector>

class MyClass {
public:
    // Member function to add an element to the vector
    void addElement(int element) {
        myVector.push_back(element);
    }

    // Member function to get the sum of all elements in the vector
    int getSum() {
        int sum = 0;
        for (int i = 0; i < myVector.size(); ++i) {
            sum += myVector[i];
        }
        return sum;
    }

    // Member function to print all elements in the vector
    void printElements() {
        for (int i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> myVector;  // Vector as a member of the class
};

int main() {
    MyClass obj;
    obj.addElement(10);
    obj.addElement(20);
    obj.addElement(30);

    obj.printElements();  // Output: 10 20 30
    std::cout << "Sum: " << obj.getSum() << std::endl;  // Output: Sum: 60

    return 0;
}
