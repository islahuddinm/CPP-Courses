#include <iostream>
#include <iomanip>

class cars {
public:
    cars() { // default constructor
        std::cout << "Default costructor is called.\n";
    }
    cars(std::string brandParam, std::string typeParam, int yearsParam, double priceParam); // custom constructor
    ~cars();

    void run() {
        std::cout << "run fast" << std::endl;
    }
    
    int speed = 100;
private:
    std::string brand;
    std::string type;
    int *years;
    double *price;
};

cars::cars(std::string brandParam, std::string typeParam, int yearsParam, double priceParam) { // custom Constructor

    brand = brandParam;
    type = typeParam;
    years = new int (yearsParam);
    price = new double (priceParam);

    std::cout << brand << " " << type << " " << *years << " " << std::fixed << std::setprecision(0) << *price << '\n';
};

cars::~cars() { // Destructor is always have '~'(tilde sign) in prefix.

    delete years, price;
    
    std::cout << "Destructor called for address of " << brand << " : " << years << " & " << price << '\n';
};

void function2() {

    cars mclaren("Mclaren", "Spider 720", 2023, 1000000);
}

void function3(cars paganiParam) {

    
}

void function4() { // this is how to destruct explicitly.

    // this create "heap object". it means create object at heap memory.
    cars *lamborgini = new cars("Lamborgini", "Aventado", 2020, 3000000);

    std::cout << (*lamborgini).speed << std::endl; // "(*lamborgini)." to call heap object variable
    std::cout << lamborgini->speed << std::endl; // "lamborgini->" another way to call heap object variable

    delete lamborgini;
}

int main() {

    // this create "stack object". it means create object at stack memory.
    cars pagani("Pagani", "Hyura", 2022, 2000000);

    cars italy = pagani;

    std::cout << italy.speed << '\n';
    //std::cout << italy.run() << '\n'; // this would be error instead is "italy.run()" below. because there is any return
    italy.run();

    cars *italy2 = &pagani;

    std::cout << (*italy2).speed << '\n'; // a way to call if we are using pointer.
    std::cout << italy2->speed << '\n'; // another way

    function2();
    function3(pagani); // this is how to put 'pagani' to function3 by parameter and the destructor will execute in function3.
    function4();

   cars ferrari; // this create object and call default constructor.
    
    std::cout << "Done" << '\n';

    return 0;
}

// keep in mind if you want to understand this ///////////////////////////////////////////////////////////
// you have to know 'constructor, destructor, new, delete, and class files before.////////////////////////