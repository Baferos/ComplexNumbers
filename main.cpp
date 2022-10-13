#include <iostream>
#include "Complex.hpp"

int main() {
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c = a /  b;
    auto d = c;
    std::cout << a * b << std::endl;
    c.printExponential();
    d.printExponential();
    d.printPolar();
    c.printExponential();
    return 0;
}
