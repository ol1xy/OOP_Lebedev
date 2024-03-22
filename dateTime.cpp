#include <iostream>
#include <stdexcept>

using namespace std;

class DateTime {
public:
    int day;
    int month;
    int year;

public:
    // Конструктор
    DateTime(int day, int month, int year) {
        if (!isValidDate(day, month, year)) {
            throw invalid_argument("Invalid date!");
        }
        this->day = day;
        this->month = month;
        this->year = year;
    }

    // Перегрузка оператора <<
    friend ostream& operator<<(ostream& os, const DateTime& dt) {
        os << dt.day << "." << dt.month << "." << dt.year;
        return os;
    }

    // Перегрузка оператора >> 
    friend istream& operator>>(istream& is, DateTime& dt) {
        char c;
        is >> dt.day >> c >> dt.month >> c >> dt.year;
        if (c != '.') {
            throw invalid_argument("Incorrect date format!");
        }
        return is;
    }

    // Проверка корректности даты
    bool isValidDate(int day, int month, int year) const {
        if (day < 1 || day > 31) {
            return false;
        }
        if (month < 1 || month > 12) {
            return false;
        }
        if (year < 1) {
            return false;
        }
        if (isLeapYear() && month == 2 && day > 29) {
            return false;
        }
        if (!isLeapYear() && month == 2 && day > 28) {
            return false;
        }
        return true;
    }

    // Определение високосности года по юлианской дате
    bool isLeapYear() const {
        int jd = getJulianDay();
        return ((jd % 4) == 0);
    }

    // Подсчет юлианской даты
    int getJulianDay() const {
        int a = (14 - month) / 12;
        int y = year + 4800 - a;
        int m = month + 12 * a - 3;
        return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    }
};

int main() {
    try {
        int day, month, year;
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;

        DateTime dt(day, month, year);
        cout << "Entered date: " << dt << endl;

    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
