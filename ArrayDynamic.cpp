#include <iostream>

int main() {

    double *temperature = new double[] {1, 4, 2, 3, 5};

    for(double temp : temperature) {

        std::cout << "temperatur : " << temp << '/n';
    }

    return 0;
}

// this is not working, look at "OperatorNewDelet2"