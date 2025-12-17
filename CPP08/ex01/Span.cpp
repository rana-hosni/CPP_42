#include "Span.hpp"

Span::Span() : _maxSize(0) {}
Span::Span(unsigned int n) : _maxSize(n) {}
Span::Span(const Span &copy): _maxSize(copy._maxSize), _numbers(copy._numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int newNumber){
    if (_numbers.size() >= _maxSize) {
        throw SpanIsFull();
    }
    _numbers.push_back(newNumber);
}