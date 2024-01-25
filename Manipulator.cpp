#include <iostream>

int main() {

    int hex = 0x10; //hexadecimal number
    int oct = 010; //octal number
    int bin = 0b1101; //binary number
    int number1 = 1055; //decimal number
    
    //std::hex, std::oct, & std::dec they will be not effect on floating number
    std::cout << hex << '\n';
    std::cout << oct << '\n';
    std::cout << bin << '\n';
    std::cout << std::hex << number1 << '\n'; //convert decimal to hexadecimal
    std::cout << std::oct << number1 << '\n'; //convert decimal to octal
    std::cout << std::dec << bin << '\n'; //convert bin to decimal
    std::cout << '\n';

    std::cout << std::showbase; //it is to show number code
    std::cout << std::uppercase; //it is to make uppercase text
    std::cout << "number1 vatiable(des) : " << std::dec << number1 << '\n';
    std::cout << "number1 vatiable(hex) : " << std::hex << number1 << '\n';
    std::cout << "number1 vatiable(oct) : " << std::oct << number1 << '\n';
    std::cout << '\n';

    return 0;
}