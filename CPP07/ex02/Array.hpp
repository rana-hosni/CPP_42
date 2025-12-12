#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        T *elements;
        unsigned int size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array<T> &operator=(const Array &other);

        ~Array();

};

#endif