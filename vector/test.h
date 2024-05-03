#pragma once
#include <iostream>
#include "Vector.h"

using namespace std;

void test_push_back() {
    Vector<int> vec;

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    for (int i = 0; i < 10; ++i) {
        if (vec[i] != i) {
            cout << "Ошибка при добавлении элемента: " << i << endl;
            return;
        }
    }

    cout << "Тест push_back пройден успешно!" << endl;
}

void test_erase() {
    Vector<int> vec;

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    vec.erase(5);

    if (vec.getSize() != 9 || vec[5] != 6) {
        cout << "Ошибка при удалении элемента!" << endl;
        return;
    }

    cout << "Тест erase пройден успешно!" << endl;
}

void test_insert() {
    Vector<int> vec;

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    vec.insert(3, 55);

    if (vec.getSize() != 11 || vec[3] != 55 || vec[4] != 3) {
        cout << "Ошибка при вставке элемента!" << endl;
        return;
    }

    cout << "Тест insert пройден успешно!" << endl;
}

void test_get() {
    Vector<int> vec;

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    for (int i = 0; i < 10; ++i) {
        if (vec[i] != i) {
            cout << "Ошибка при получении элемента: " << i << endl;
            return;
        }
    }

    cout << "Тест get пройден успешно!" << endl;
}
