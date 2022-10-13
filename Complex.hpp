#ifndef UUID_D74592B69E5242EBB8E0E13BE6F30C2C
#define UUID_D74592B69E5242EBB8E0E13BE6F30C2C
#include <iostream>
#include <cmath>


class Complex {
private:
    double real;
    double imaginary;

public:
    //Constructors
    Complex(double real, double imaginary);
    Complex();

    Complex(Complex &other);

    Complex(const Complex &&other);

    Complex operator=(const Complex &other);
    Complex operator=(const Complex &&other);

    //Destructor
    ~Complex() = default;

    //Getters
    double getReal() const;
    double getImaginary() const;

    //Setters
    void setReal(double real);
    void setImaginary(double imaginary);

    Complex operator+(const Complex &other) const;
    Complex operator-(const Complex &other) const;

    Complex operator*(const Complex &other) const;
    Complex operator/(const Complex &other) const;

    bool operator==(const Complex &other) const;
    bool operator!=(const Complex &other) const;

    Complex operator+=(const Complex &other);
    Complex operator-=(const Complex &other);

    Complex operator*=(const Complex &other);
    Complex operator/=(const Complex &other);

    Complex operator++();
    Complex operator++(int);

    Complex operator--();
    Complex operator--(int);

    double modulus() const;
    double argument() const;

    void printPolar() const;
    void printCartesian() const;
    void printExponential() const;

    friend std::ostream &operator<<(std::ostream &out, const Complex &c);
    friend std::istream &operator>>(std::istream &in, Complex &c);

};
#endif //UUID_D74592B69E5242EBB8E0E13BE6F30C2C
