#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <cmath>

class Rational {
private:

    long long numer;
    long long denom;

public:
    Rational();

    Rational(int n = 0, int d = 1); // Конструктор, принимающий числитель и знаменатель
    int numerator() const { return numer; }
    int denominator() const { return denom; }

    explicit Rational(const Rational& numerator, const Rational& denominator);

    explicit Rational(Rational& number);

    explicit Rational(const Rational& number);

    explicit Rational(Rational rational, long long number);

    explicit Rational(int number, Rational rational);

    long long getNumerator() const;
    long long getDenominator() const;

    void simplify();

    long long isLongLongRange(long long value) const {
        if (value >= std::numeric_limits<long long>::min() && value <= std::numeric_limits<long long>::max()) {
            return value;
        }
        else {
            throw "Overflow";
        }
    };

    long double sqrts() {
        long long p = numer;
        long long q = denom;
        long double x0 = sqrt(static_cast<long double>(p) / q); // начальное приближение
        long double x = x0;

        for (int i = 0; i < 4; ++i) {
            x = 0.5L * (x + p / (q * x)); // метод последовательных приближений
        }

        return x;
    };
};

#endif //RATIONAL_RATIONAL_H
