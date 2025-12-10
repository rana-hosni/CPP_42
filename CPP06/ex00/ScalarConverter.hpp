#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static void printChar(std::string literal);
        static bool isInt(std::string literal);
        static void wrongLiteral();
        static bool isNumber(std::string literal);
        // static bool isDouble(std::string literal);
        static void printImpossible(std::string literal);
    public:
        static void convert(std::string literal);
};

#endif