#include <iostream>
#include "ComplexNumber.h"
#include "Rational.h"  // Включаем заголовочный файл для класса Rational

int main() {
    std::string real1, imag1, real2, imag2;
    int base;
    double exponent;
    int numerator, denominator;

    std::cout << "Enter base: ";
    std::cin >> base;

    std::cout << "Enter real part of first complex number: ";
    std::cin >> real1;
    std::cout << "Enter imaginary part of first complex number: ";
    std::cin >> imag1;

    ComplexNumber c1(real1, imag1, base);

    std::cout << "Enter real part of second complex number: ";
    std::cin >> real2;
    std::cout << "Enter imaginary part of second complex number: ";
    std::cin >> imag2;

    ComplexNumber c2(real2, imag2, base);

    // Демонстрация сложения
    ComplexNumber sum = c1 + c2;
    std::cout << "Sum: " << sum << std::endl;

    // Демонстрация вычитания
    ComplexNumber diff = c1 - c2;
    std::cout << "Difference: " << diff << std::endl;

    // Демонстрация умножения
    ComplexNumber prod = c1 * c2;
    std::cout << "Product: " << prod << std::endl;

    // Демонстрация деления
    ComplexNumber quot = c1 / c2;
    std::cout << "Quotient: " << quot << std::endl;

    // Демонстрация возведения в степень (целое число)
    std::cout << "Enter integer exponent: ";
    std::cin >> exponent;
    ComplexNumber powInt = c1.pow(static_cast<int>(exponent));
    std::cout << "Power (int): " << powInt << std::endl;

    // Демонстрация возведения в степень (дробное число)
    std::cout << "Enter floating point exponent: ";
    std::cin >> exponent;
    ComplexNumber powDouble = c1.pow(exponent);
    std::cout << "Power (double): " << powDouble << std::endl;

    // Демонстрация возведения в степень (рациональный показатель)
    std::cout << "Enter rational exponent (numerator and denominator): ";
    std::cin >> numerator >> denominator;
    Rational rationalExponent(numerator, denominator);
    ComplexNumber powRational = c1.pow(rationalExponent);
    std::cout << "Power (rational): " << powRational << std::endl;

    // Демонстрация вычисления модуля
    double modulus = c1.modulus();
    std::cout << "Modulus: " << modulus << std::endl;

    // Решение квадратного уравнения
    std::cout << "Solving quadratic equation ax^2 + bx + c = 0" << std::endl;
    double a, b, c;
    std::cout << "Enter coefficient a: ";
    std::cin >> a;
    std::cout << "Enter coefficient b: ";
    std::cin >> b;
    std::cout << "Enter coefficient c: ";
    std::cin >> c;

    ComplexNumber root1, root2;
    solveQuadraticEquation(a, b, c, root1, root2);

    std::cout << "Roots of the equation are: " << root1 << " and " << root2 << std::endl;

    return 0;
}
