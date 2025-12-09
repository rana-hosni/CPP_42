#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printImpossible(std::string literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "+inff" || literal == "-inff" || literal == "nanf")
        std::cout << "float: " << literal << std::endl;
    else
        std::cout << "float: " << literal << "f" << std::endl;

    if (literal == "+inff")
        std::cout << "double: +inf" << std::endl;
    else if (literal == "-inff")
        std::cout << "double: -inf" << std::endl;
    else if (literal == "nanf")
        std::cout << "double: nan" << std::endl;
    else
        std::cout << "double: " << literal << std::endl;

}

void ScalarConverter::printChar(std::string literal){
    char c = literal[0];
    if (!isprint(c)) {
        std::cout << "char: Non displayable" << std::endl;
    } 
    else {
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
}

bool ScalarConverter::isInt(std::string literal) {
    char* end;
    long val = std::strtol(literal.c_str(), &end, 10);
    if (*end != '\0')
        return false;
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        return false;
    return true;
}

void ScalarConverter::convert(std::string literal) {
    if (literal.length() == 1 && !isdigit(literal[0])) {
        ScalarConverter::printChar(literal);
        return;
    }
    else if (literal == "+inf" || literal == "-inf" || literal == "nan" ||
             literal == "+inff" || literal == "-inff" || literal == "nanf") {
        ScalarConverter::printImpossible(literal);
        return;
    }
    else if (ScalarConverter::isInt(literal)) {//Needs modification to handle longer numbers Refactor later
        int val = std::atoi(literal.c_str());
        if (val >= 32 && val <= 126)
            std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << val << std::endl;
        std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
        return;
    }
    
    // }
}
