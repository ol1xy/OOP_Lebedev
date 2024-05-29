#include "ComplexNumber.h"
#include <algorithm>
#include <cmath>

// Конструктор
ComplexNumber::ComplexNumber(const std::string& r, const std::string& i, int b) : real(r), imag(i), base(b) {}

// Преобразование числа из строки в десятичное представление
int ComplexNumber::toDecimal(const std::string& num) const {
    int value = 0;
    bool isNegative = (num[0] == '-');
    for (char digit : num) {
        if (digit == '-') continue;
        value = value * base + (isdigit(digit) ? digit - '0' : digit - 'A' + 10);
    }
    return isNegative ? -value : value;
}

// Преобразование числа из десятичного представления в строку
std::string ComplexNumber::fromDecimal(int num) const {
    if (num == 0) return "0";
    std::string result;
    bool isNegative = num < 0;
    if (isNegative) num = -num;
    while (num > 0) {
        int remainder = num % base;
        result.push_back((remainder < 10) ? remainder + '0' : remainder - 10 + 'A');
        num /= base;
    }
    if (isNegative) result.push_back('-');
    std::reverse(result.begin(), result.end());
    return result;
}

// Сложение
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    int realSum = toDecimal(real) + toDecimal(other.real);
    int imagSum = toDecimal(imag) + toDecimal(other.imag);
    return ComplexNumber(fromDecimal(realSum), fromDecimal(imagSum), base);
}

// Вычитание
ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    int realDiff = toDecimal(real) - toDecimal(other.real);
    int imagDiff = toDecimal(imag) - toDecimal(other.imag);
    return ComplexNumber(fromDecimal(realDiff), fromDecimal(imagDiff), base);
}

// Умножение
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    int realPart = toDecimal(real) * toDecimal(other.real) - toDecimal(imag) * toDecimal(other.imag);
    int imagPart = toDecimal(real) * toDecimal(other.imag) + toDecimal(imag) * toDecimal(other.real);
    return ComplexNumber(fromDecimal(realPart), fromDecimal(imagPart), base);
}

// Деление
ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    int denominator = toDecimal(other.real) * toDecimal(other.real) + toDecimal(other.imag) * toDecimal(other.imag);
    int realPart = (toDecimal(real) * toDecimal(other.real) + toDecimal(imag) * toDecimal(other.imag)) / denominator;
    int imagPart = (toDecimal(imag) * toDecimal(other.real) - toDecimal(real) * toDecimal(other.imag)) / denominator;
    return ComplexNumber(fromDecimal(realPart), fromDecimal(imagPart), base);
}

// Возведение в степень (целочисленный показатель)
ComplexNumber ComplexNumber::pow(int exponent) const {
    ComplexNumber result("1", "0", base);
    ComplexNumber base(*this);
    int exp = std::abs(exponent);
    while (exp > 0) {
        if (exp % 2 == 1)
            result = result * base;
        base = base * base;
        exp /= 2;
    }
    if (exponent < 0)
        return ComplexNumber("1", "0", base.getBase()) / result;
    return result;
}

// Возведение в степень (дробный показатель)
ComplexNumber ComplexNumber::pow(double exponent) const {
    double magnitude = std::pow(modulus(), exponent);
    double angle = std::atan2(toDecimal(imag), toDecimal(real)) * exponent;
    int realPart = static_cast<int>(magnitude * std::cos(angle));
    int imagPart = static_cast<int>(magnitude * std::sin(angle));
    return ComplexNumber(fromDecimal(realPart), fromDecimal(imagPart), base);
}

// Возведение в степень (рациональный показатель)
ComplexNumber ComplexNumber::pow(const Rational& exponent) const {
    double expValue = static_cast<double>(exponent.numerator()) / exponent.denominator();
    return pow(expValue);
}

// Модуль комплексного числа
double ComplexNumber::modulus() const {
    return std::sqrt(std::pow(toDecimal(real), 2) + std::pow(toDecimal(imag), 2));
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const ComplexNumber& c) {
    out << c.real << "+" << c.imag << "i (base " << c.base << ")";
    return out;
}

// Функция для решения квадратного уравнения
void solveQuadraticEquation(double a, double b, double c, ComplexNumber& root1, ComplexNumber& root2) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        double sqrtDiscriminant = std::sqrt(discriminant);
        double realRoot1 = (-b + sqrtDiscriminant) / (2 * a);
        double realRoot2 = (-b - sqrtDiscriminant) / (2 * a);
        root1 = ComplexNumber(std::to_string(realRoot1), "0", 10);
        root2 = ComplexNumber(std::to_string(realRoot2), "0", 10);
    }
    else {
        double realPart = -b / (2 * a);
        double imagPart = std::sqrt(-discriminant) / (2 * a);
        root1 = ComplexNumber(std::to_string(realPart), std::to_string(imagPart), 10);
        root2 = ComplexNumber(std::to_string(realPart), std::to_string(-imagPart), 10);
    }
}
