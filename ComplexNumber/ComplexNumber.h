#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
#include <cmath>
#include <string>
#include "Rational.h"

class ComplexNumber {
private:
    std::string real;
    std::string imag;
    int base;

    int toDecimal(const std::string& num) const;
    std::string fromDecimal(int num) const;

public:
    // Конструкторы
    ComplexNumber(const std::string& r = "0", const std::string& i = "0", int b = 10);

    // Методы доступа
    std::string getReal() const { return real; }
    std::string getImag() const { return imag; }
    int getBase() const { return base; }
    void setReal(const std::string& r) { real = r; }
    void setImag(const std::string& i) { imag = i; }
    void setBase(int b) { base = b; }

    // Арифметические операции
    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;

    // Возведение в степень
    ComplexNumber pow(int exponent) const;
    ComplexNumber pow(double exponent) const;
    ComplexNumber pow(const Rational& exponent) const;

    // Модуль комплексного числа
    double modulus() const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& c);
};

// Функция для решения квадратного уравнения
void solveQuadraticEquation(double a, double b, double c, ComplexNumber& root1, ComplexNumber& root2);

#endif // COMPLEXNUMBER_H
