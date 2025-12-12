#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(nullptr), size(0) {
}
template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), size(n) {
}

template <typename T>
Array<T>::Array(const Array &copy){
    size = copy.size;
    elements = new T[size];
    for (unsigned int i = 0; i < size; i++) {
        elements[i] = copy.elements[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        elements = new T[size];
        for (unsigned int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] elements;
}