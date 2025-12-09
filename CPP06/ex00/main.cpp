#include "ScalarConverter.hpp"

void testcases() {
    ScalarConverter::convert("a");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("42");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("0");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("4.2f");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("4.2");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("z");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("256");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("12345678901234567890");
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("3.4028235e+38f"); // float max
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("1.7976931348623157e+308"); // double max
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Wrong number of arguments, Please Enter only one argument" << std::endl;
        testcases();//TOBE REMOVED LATER
        return 1;
    }
    else {
        std::string literal = argv[1];
        ScalarConverter::convert(literal);
    }

    return 0;
}