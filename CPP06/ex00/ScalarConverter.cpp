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
    // if (literal != "+inf" && literal != "-inf" && literal != "nan" &&
    //     literal != "+inff" && literal != "-inff" && literal != "nanf") {
    //     if ()
    // }

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

void ScalarConverter::wrongLiteral() {
    std::cout<< "char:   impossible" << std::endl;
    std::cout<< "int:    impossible" << std::endl;
    std::cout<< "float:  impossible" << std::endl;
    std::cout<< "double: impossible" << std::endl;
}

bool ScalarConverter::isNumber(std::string literal) {
    char* end;
    try{
        std::strtod(literal.c_str(), &end);
    }
    catch (...) {
        return false;
    }
    return *end == '\0' || (*end == 'f' && *(end + 1) == '\0');
}

void ScalarConverter::convert(std::string literal) {
    if (literal.length() == 1 && !isdigit(literal[0])) {
        ScalarConverter::printChar(literal);
        return;
    }
    else if (!ScalarConverter::isNumber(literal)) {
        ScalarConverter::wrongLiteral();
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
    else if (literal.find('.') != std::string::npos) {
        char* end;
        double val = std::strtod(literal.c_str(), &end);
        if (*end == 'f' && *(end + 1) == '\0') { // It's a float
            float fval = static_cast<float>(val);
            if (fval >= 32 && fval <= 126 && fval == static_cast<int>(fval))
                std::cout << "char: '" << static_cast<char>(fval) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
            if (fval >= std::numeric_limits<int>::min() && fval <= std::numeric_limits<int>::max())
                std::cout << "int: " << static_cast<int>(fval) << std::endl;
            else
                std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << fval << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(fval) << std::endl;
            return;
        }
        else if (*end == '\0') { // It's a double
            if (val >= 32 && val <= 126 && val == static_cast<int>(val))
                std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
            if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
                std::cout << "int: " << static_cast<int>(val) << std::endl;
            else
                std::cout << "int: impossible" << std::endl;
            if (val >= -std::numeric_limits<float>::max() && val <= std::numeric_limits<float>::max())
                std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
            else
                std::cout << "float: impossible" << std::endl;
            std::cout << "double: " << val << std::endl;
            return;
        } 
    }
    else {
        ScalarConverter::wrongLiteral();
        return;
    }  
}
