#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

class RPN {
    private:
        std::stack<int> _numbers;
        int _result;

    public:
        RPN();
        ~RPN();
        // RPN(const RPN& other);
        // RPN& operator=(const RPN& other);
        void acceptInput(const std::string& input);
        int calculate(char op);
};

#endif