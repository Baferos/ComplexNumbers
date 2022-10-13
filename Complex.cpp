#include "Complex.hpp"

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

Complex::Complex() : real(0), imaginary(0) {}

double Complex::getReal() const {
    return this->real;
}

double Complex::getImaginary() const {
    return this->imaginary;
}

void Complex::setReal(double real) {
    this->real = real;
}

void Complex::setImaginary(double imaginary) {
    this->imaginary=imaginary;
}

Complex Complex::operator+(const Complex &other) const {
    return Complex(this->real + other.real, this->imaginary + other.imaginary);
}

Complex Complex::operator*(const Complex &other) const {
    return Complex(this->real * other.real - this->imaginary * other.imaginary,
                   this->real * other.imaginary + this->imaginary * other.real);
}

Complex Complex::operator-(const Complex &other) const {
    return Complex(this->real - other.real, this->imaginary - other.imaginary);
}

Complex Complex::operator/(const Complex &other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    return Complex((this->real * other.real + this->imaginary * other.imaginary) / denominator,
                   (this->imaginary * other.real - this->real * other.imaginary) / denominator);
}

double Complex::modulus() const {
    return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}

bool Complex::operator==(const Complex &other) const {
    return this->real == other.real && this->imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex &other) const {
    return this->real != other.real || this->imaginary != other.imaginary;
}

Complex Complex::operator+=(const Complex &other) {
    this->real += other.real;
    this->imaginary += other.imaginary;
    return *this;
}

Complex Complex::operator*=(const Complex &other) {
    double real = this->real * other.real - this->imaginary * other.imaginary;
    double imaginary = this->real * other.imaginary + this->imaginary * other.real;
    this->real = real;
    this->imaginary = imaginary;
    return *this;
}

Complex Complex::operator-=(const Complex &other) {
    this->real -= other.real;
    this->imaginary -= other.imaginary;
    return *this;
}

Complex Complex::operator/=(const Complex &other) {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    double real = (this->real * other.real + this->imaginary * other.imaginary) / denominator;
    double imaginary = (this->imaginary * other.real - this->real * other.imaginary) / denominator;
    this->real = real;
    this->imaginary = imaginary;
    return *this;
}

Complex Complex::operator++() {
    this->real++;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    this->real++;
    return temp;
}

Complex Complex::operator--() {
    this->real--;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp = *this;
    this->real--;
    return temp;
}

std::ostream &operator<<(std::ostream &out, const Complex &c) {
    out << c.real << " + " << c.imaginary << "i";
    return out;
}

std::istream &operator>>(std::istream &in, Complex &c) {
    in >> c.real >> c.imaginary;
    return in;
}

Complex Complex::operator=(const Complex &other) {
    this->real = other.real;
    this->imaginary = other.imaginary;
    return *this;
}

Complex::Complex(Complex &other) {
    this->real = other.real;
    this->imaginary = other.imaginary;
}

Complex::Complex(const Complex &&other) {
    this->real = other.real;
    this->imaginary = other.imaginary;
}


Complex Complex::operator=(const Complex &&other) {
    this->real = other.real;
    this->imaginary = other.imaginary;
    return *this;
}

double Complex::argument() const {
    return atan2(this->imaginary, this->real);
}

void Complex::printPolar() const {
    std::cout << this->modulus() << " * (cos(" << this->argument() << ") + i * sin(" << this->argument() << "))" << std::endl;
}

void Complex::printCartesian() const {
    std::cout << this->real << " + " << this->imaginary << "i" << std::endl;
}

void Complex::printExponential() const {
    std::cout << this->modulus() << " * e^(" << this->argument() << "i)" << std::endl;
}