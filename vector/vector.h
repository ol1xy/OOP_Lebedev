#include <iostream>
#include <algorithm>

template <typename T>
class Vector {

private:
    T* array; // Указатель на первый элемент массива
    size_t capacity; // Размер выделенной памяти
    size_t size; // Текущий размер вектора

public:
    Vector(); // Конструктор по умолчанию
    Vector(size_t initial_size); // Конструктор с заданным начальным размером
    ~Vector(); // Деструктор

    void push_back(const T& value); // Метод добавления элемента в конец вектора
    void erase(size_t index); // Метод удаления элемента из указанной позиции
    void insert(size_t index, const T& value); // Метод добавления элемента в указанную позицию
    const T& operator[](size_t index) const; // Проверка индекса
    size_t getSize() const;  // Метод получения размера вектора
    void reserve(size_t new_capacity);  // Метод выделения памяти для вектора   

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& out, const Vector<T>& vec);
};

    template <typename T>
    Vector<T>::Vector() : array(nullptr), capacity(0), size(0) {}

    template <typename T>
    Vector<T>::Vector(size_t initial_size) : array(new T[initial_size]), capacity(initial_size), size(initial_size) {}

    template <typename T>
    Vector<T>::~Vector() {
        delete[] array;
    }

    template <typename T>
    void Vector<T>::push_back(const T& value) {
        if (size >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        array[size++] = value;
    }

    template <typename T>
    void Vector<T>::erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы вектора");
        }
        for (size_t i = index; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        --size;
    }

    template <typename T>
    void Vector<T>::insert(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Индекс выходит за пределы вектора");
        }
        if (size >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        for (size_t i = size; i > index; --i) {
            array[i] = array[i - 1];
        }
        array[index] = value;
        ++size;
    }

    template <typename T>
    const T& Vector<T>::operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы вектора");
        }
        return *(array + index);
    }

    template <typename T>
    size_t Vector<T>::getSize() const {
        return size;
    }

    template <typename T>
    void Vector<T>::reserve(size_t new_capacity) {
        if (new_capacity <= capacity) {
            return;
        }
        T* new_array = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_array[i] = std::move(array[i]);
        }
        delete[] array;
        array = new_array;
        capacity = new_capacity;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& out, const Vector<T>& vec) {
        out << "[";
        for (size_t i = 0; i < vec.size; ++i) {
            out << vec.array[i];
            if (i != vec.size - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    };
