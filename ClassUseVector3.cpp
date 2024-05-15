#include <iostream>
#include <vector>

class MyClass {
public:
    // Member function to add an element to the vector
    void addElement(int element) {
        myVector.push_back(element);
    }

    // Member function to get a reference to the vector
    std::vector<int>& getVector() {
        return myVector;
    }

private:
    std::vector<int> myVector;  // Vector as a member of the class
};

// Function outside the class to print the vector
void printVector(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    MyClass obj;
    obj.addElement(10);
    obj.addElement(20);
    obj.addElement(30);

    std::vector<int>& vec = obj.getVector();
    printVector(vec);  // Output: 10 20 30

    return 0;
}
