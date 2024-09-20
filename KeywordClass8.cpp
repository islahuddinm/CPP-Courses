#include <iostream>

class McLaren {
public:
    // Nested class Ferari
    class Ferari {
    public:
        void fix() {
            std::cout << "Fix Ferari" << std::endl;
        }
    };

    // Public method to return Ferari object
    Ferari getFerari() {
        return ferari;
    }

    // Constructor of McLaren class
    McLaren() {
        // Call fix() on ferari, which is a member of McLaren
        ferari.fix();

        // Call fix() on the object returned by getFerari()
        getFerari().fix();

        // Initialize ferari2 using getFerari() and call fix()
        ferari2 = getFerari();
        ferari2.fix();

        // Call fix() on ferari3
        ferari3.fix();
    }

private:
    Ferari ferari;    // Member object of class Ferari
    Ferari ferari2;   // Another Ferari object
    Ferari ferari3;   // Another Ferari object (not initialized in constructor)
};

int main() {
    McLaren mclaren;  // Instantiate McLaren, which will call the constructor

    return 0;
}
