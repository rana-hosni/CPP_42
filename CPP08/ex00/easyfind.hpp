#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <iterator>
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Element not found in the container.";
        }
};

class EmptyContainerException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "The container is empty.";
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int number){
    if (container.empty())
        throw EmptyContainerException();
    typename T::iterator found;
    found = std::find(container.begin(), container.end(), number);
    if (found == container.end())
        throw NotFoundException();
    return found;
}


#endif