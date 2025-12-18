#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

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

        int shortestSpan();
        int longestSpan();
        // void iteratorAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        std::vector<int> getNumbers() const;
    class SpanIsFull: public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Span is full. Cannot add more numbers.";
            }
    };

    class SpanNotFound: public std::exception{
        public:
            virtual const char* what() const throw() {
                return "No Span Found!";
            }
    };

};

#endif