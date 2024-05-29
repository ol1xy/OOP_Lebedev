#include "Rational.h"
#include <cmath>

Rational::Rational(int n, int d) : numer(n), denom(d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    // Можно добавить нормализацию дроби, если необходимо
}


long long Rational::getNumerator() const {
    return numer;
}

long long Rational::getDenominator() const {
    return denom;
}

Rational::Rational() {
    numer = 0;
    denom = 1;
};



Rational::Rational(const Rational& numerator, const Rational& denominator) {
    this->numer = isLongLongRange(numerator.numer * denominator.denom);
    this->denom = isLongLongRange(numerator.denom * denominator.numer);
    simplify();
}

Rational::Rational(Rational& number) {
    numer = number.numer;
    denom = number.denom;
    simplify();
}

Rational::Rational(const Rational& rational) {
    numer = rational.numer;
    denom = rational.denom;
    simplify();
}

Rational::Rational(Rational rational, long long number) {
    numer = isLongLongRange(number * rational.denom + rational.numer);
    denom = isLongLongRange(number * rational.denom + rational.denom);
    simplify();
}

Rational::Rational(int number, Rational rational) {
    numer = isLongLongRange(number * rational.denom + rational.numer);
    denom = isLongLongRange(number * rational.denom + rational.denom);
    simplify();
}

long long NSD(long long a, long long b) {

    while (a != b) {
        if (a > b) {
            a -= b;

        }
        else {
            b -= a;
        }
    }
    return a;

}

void Rational::simplify() {
    long long nod;

    if (denom < 0) {
        numer = -numer;
        denom = -denom;
    }
    else {
        while (NSD(numer, denom) > 1) {
            nod = NSD(numer, denom);
            numer /= nod;
            denom /= nod;
        }
    }
}
