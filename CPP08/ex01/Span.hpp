#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>

class Span {
    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int newNumber);

    class SpanIsFull: public std::exception {
        public:
            const char* what() const noexcept override {
                return "Span is full. Cannot add more numbers.";
            }
    };

};

#endif