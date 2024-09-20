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

    // Constructor for McLaren
    McLaren() {
        // Call fix() on ferari
        ferari.fix();

        // Call fix() on the object returned by getFerari()
        getFerari().fix();
    }

    // Public method to return Ferari object
    Ferari getFerari() {
        return ferari;
    }

private:
    Ferari ferari;  // Member object of class Ferari
};

int main() {
    // Create a McLaren object
    McLaren mclaren;  // The constructor will be called here

    return 0;
}
