#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, const size_t length, void (*fun)(T &)) {
    for (size_t i = 0; i < length; i++) {
        fun(array[i]);
    }
}

template <typename T>
void iter(const T *array, const size_t length, void (*fun)(const T &)) {
    for (size_t i = 0; i < length; i++) {
        fun((array[i]));
    }
}

template <typename T>
void printElement(const T &element) {
    std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T &element) {
    ++element;
}


#endif