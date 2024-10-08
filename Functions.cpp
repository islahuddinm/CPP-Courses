#include <iostream>

//void is return type

//function that take a single parameter/argument, and doen't gave back the result explicitly.
void enter_bar(size_t age) { //"unsigned int age" is function parameter

    if (age > 18) {

        std::cout << "you are " << age << " years old" << '\n';
    }

    else {
        
        std::cout << "sorry, you are too young for this\n";
    }
}

//function that takes multiple parameters/arguments and returns the result of the computation
int max(int c, int b) {

    // a++; would be error because it cannot reach out in main function

    if (c > b) {

        // a++; would be error because it cannot reach out in main function
        c++;

        return c;
    }

    else {
        
        return b;
    }
}

int x = 9;

//function that dose not take parameters/arguments and results nothing
void sayHello() {

    int xx = x;
    std::cout << "Hello\n";
}

//function is going to increment and multiplay
double increment_multiply(double a, double b) {

    std::cout << "inside function, before increment\n";
    std::cout << "a : " << a <<'\n';
    std::cout << "b : " << b <<'\n';

    double result11 = ((++a) * (++b));

    std::cout << "inside function, after increment\n";
    std::cout << "a : " << a << '\n';
    std::cout << "b : " << b << '\n';

    return result11;
}

void ifinfunction(int a, int b) {

    std::cout << result11 <<'\n';

    int cc = 0;

    if(true) {

        int aa = a;
        cc++;

        std::cout << aa << std::endl;
    }

    //aa++; // error, we cannot access inside flow control
    //std::cout << aa << std::endl; // error, we cannot access inside flow control
    
    if(false) {

        int bb = b;

        std::cout << bb << std::endl;
        std::cout << aa << std::endl;
    }

    /* The error here stems from the fact that you cannot declare a function (declare()) inside
    another function (ifinfunction()) in standard C++ syntax. */
    void declare() {
        int dd;
    }

    dd = 44;
}

// this is declaration function
void a();

int main() {

    enter_bar(20); //funtion argument or funtion call
    enter_bar(25);
    enter_bar(16);

    for (size_t i = 16; i <= 19; ++i) {

        enter_bar(i);
    }
    std::cout << "//////////////////////////////////////////////////////////////////////////// 1\n";
    std::cout << '\n';

    int a = 7;
    int b = 5;

    int result = max(a, b);

    std::cout << "value result : " << result << '\n';
    std::cout << "value result : " << max(max(a, b), b) << '\n';
    std::cout << "value result : " << max(4, 20) << '\n';

    std::cout << "//////////////////////////////////////////////////////////////////////////// 2\n";
    std::cout << '\n';

    sayHello();
    sayHello();
    std::cout << "//////////////////////////////////////////////////////////////////////////// 3\n";
    std::cout << '\n';

    double c = 2.00;
    double d = 5.00;

    std::cout << "outside function, before increment\n";
    std::cout << "c : " << c <<'\n';
    std::cout << "d : " << d <<'\n';

    double multiple_result = increment_multiply(c, d);

    std::cout << "outside function, after increment\n";
    std::cout << "c : " << c <<'\n';
    std::cout << "d : " << d <<'\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////// 4\n";
    std::cout << '\n';

    ifinfunction(11, 22);

    /* The error here stems from the fact that you cannot declare a function (declare()) inside
    another function (ifinfunction()) in standard C++ syntax. */
    int returnint() {        
        return 0;
    }
    
    return 0;
}

// this is definition/implementation frunction
void a() {
    
    return;
}
