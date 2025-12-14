#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>

template <typename T>
class Array {
    private:
        T *_elements;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array<T> &operator=(const Array &other);
        T &operator[](unsigned int index);
        T &operator[](unsigned int index) const;
        ~Array();

        unsigned int size() const;

};

#include "Array.tpp"
#endif