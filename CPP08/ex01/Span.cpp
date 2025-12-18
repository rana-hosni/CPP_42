#include "Span.hpp"

Span::Span() : _maxSize(0) {}
Span::Span(unsigned int n) : _maxSize(n) {
    
}
Span::Span(const Span &copy): _numbers(copy._numbers), _maxSize(copy._maxSize) {}

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
std::vector<int> Span::getNumbers() const {
    return _numbers;
}

int Span::shortestSpan(){
    if (this->_numbers.size() < 2)
        throw SpanNotFound();
    int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
    int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
    return (max - min);
}

int Span::longestSpan(){
    if (this->_numbers.size() < 2)
        throw SpanNotFound();

    std::vector<int> copy = this->_numbers;
    std::sort(copy.begin(), copy.end());
    int span = copy[1] - copy[0];
    for (size_t i = 1; i + 1 < copy.size(); i++)
    {
        int dif = copy[i + 1] - copy[i];
        if (span > dif)
            span = dif;
    }
    return span;
}

// void Span::iteratorAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end){
//     for (std::vector<int>::iterator it = begin; it != end; ++it) {
//         if (_numbers.size() >= _maxSize) {
//             throw SpanIsFull();
//         }
//         _numbers.push_back(*it);
//     }
// }