### ComplexNumber Project
## Описание
Проект реализует класс для работы с комплексными числами в произвольной системе счисления и включает методы для выполнения различных арифметических операций, возведения в степень, вычисления модуля и решения квадратных уравнений с действительными коэффициентами, корни которых могут быть комплексными числами. Также используется класс Rational для работы с рациональными числами.

## Структура проекта
Проект состоит из следующих файлов:

ComplexNumber.h: Заголовочный файл, содержащий объявление класса ComplexNumber.
ComplexNumber.cpp: Файл реализации методов класса ComplexNumber.
main.cpp: Основной файл программы, содержащий демонстрацию работы с классом ComplexNumber.
Rational.h и Rational.cpp: Заголовочный файл и файл реализации класса Rational.

## Взаимодействие классов и методов

|     Rational        |
|---------------------|
| - int numerator     |
| - int denominator   |
|---------------------|
| + Rational(int, int)|
| + double toDouble() |
| + ... (другие методы)|

            ^
            |
            v

|  ComplexNumber       |
|----------------------|
| - std::string real   |
| - std::string imag   |
| - int base           |
|----------------------|
| + ComplexNumber(...) |
| + operator+(...)     |
| + operator-(...)     |
| + operator*(...)     |
| + operator/(...)     |
| + pow(int)           |
| + pow(double)        |
| + pow(Rational)      |
| + modulus()          |
| + ... (другие методы)|

            ^
            |
            v

|      main.cpp        |
|----------------------|
| - Пользовательский   |
|   ввод и вывод       |
| - Демонстрация       |
|   возможностей       |
|   ComplexNumber      |
| - Решение            |
|   квадратных         |
|   уравнений          |


## Описание классов и методов
# Rational
Класс для работы с рациональными числами.

# Поля:

int numerator: числитель.<br>
int denominator: знаменатель.<br>

# Конструкторы и методы:

Rational(int num, int denom): конструктор для инициализации числителя и знаменателя.<br>
double toDouble() const: преобразование рационального числа в число с плавающей точкой.<br>
Другие методы для выполнения арифметических операций и упрощения дробей.<br>


## ComplexNumber
Класс для работы с комплексными числами в произвольной системе счисления.

# Поля:

std::string real: действительная часть числа.<br>
std::string imag: мнимая часть числа.<br>
int base: система счисления.<br>
Конструкторы и методы:<br>

ComplexNumber(const std::string& r, const std::string& i, int b): конструктор для инициализации комплексного числа.<br>
ComplexNumber operator+(const ComplexNumber& other) const: сложение комплексных чисел.<br>
ComplexNumber operator-(const ComplexNumber& other) const: вычитание комплексных чисел.<br>
ComplexNumber operator*(const ComplexNumber& other) const: умножение комплексных чисел.<br>
ComplexNumber operator/(const ComplexNumber& other) const: деление комплексных чисел.<br>
ComplexNumber pow(int exponent) const: возведение в степень с целым показателем.<br>
ComplexNumber pow(double exponent) const: возведение в степень с дробным показателем.<br>
ComplexNumber pow(const Rational& exponent) const: возведение в степень с рациональным показателем.<br>
double modulus() const: вычисление модуля комплексного числа.<br>
Другие вспомогательные методы.

# main.cpp
Файл для демонстрации работы с классом ComplexNumber:<br>

Пользовательский ввод комплексных чисел и их характеристик.<br>
Демонстрация различных операций с комплексными числами.<br>
Решение квадратного уравнения с действительными коэффициентами, корни которого могут быть комплексными.
