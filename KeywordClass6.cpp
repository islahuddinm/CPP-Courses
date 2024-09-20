#include <iostream>
#include <string>

// Class Pagani
class Pagani {
public:
    std::string model;

    // Constructor
    Pagani(const std::string& modelName) : model(modelName) {}

    // Display function for Pagani
    void display() const {
        std::cout << model << " is ready to drive!" << std::endl;
    }
};

// Class McLaren
class McLaren {
public:
    // Method to 'run' McLaren and return a Pagani object
    Pagani run() const {
        return Pagani("Pagani Zonda");  // Returning a Pagani object
    }

    class Ferari {
        
        void fix() {

            std::cout << "Fix Ferari" << std::endl;
        }
    };
    
    /* you cannot call a class's function or method directly in the class body, outside of a function or constructor.
    it means we cannot call class's function because we dont put function call inside a constractor.
    Check "KeywordClass8.cpp", "KeywordClass9.cpp" is correct way. */

    Ferari getFerari() {

        return ferari;
    }

    Ferari getFerari() {

        return Ferari ferari5;
    }

    Ferari ferari2 = getFerari();
    Ferari ferari3;

    ferari.fix();
    getFerari().fix();
    
    ferari2.fix();

    ferari3.fix();

private:
    Ferari ferari;
};

int main() {
    McLaren mclaren;
    McLaren::Ferari ferari4;

    mclaren.ferari2.fix();
    mclaren.ferari3.fix();
    ferari4 = mclaren.getFerari();

    // Call mclaren.run() and store the result in pagani
    Pagani pagani = mclaren.run();

    // Display the details of the pagani object
    pagani.display();

    return 0;
}
