#include "RPN.hpp"

RPN::RPN() : numberCount(0), operationCount(0), _result(0) {}
RPN::~RPN() {}

void RPN::acceptInput(const std::string& input){
    for (size_t i = 0; i < input.length(); i++){
        try{
            if (!isspace(input[i]) && !isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/'){
                throw std::invalid_argument("Error");
            }
        }
        catch (const std::invalid_argument& e){
            std::cerr << e.what() << std::endl;
            return;
        }
        if (isdigit(input[i])){
            _numbers.push(input[i] - '0');
            numberCount++;
        }
        else if (input[i] == ' '){
            continue;
        }
        else {
            if (_numbers.size() < 2){
                std::cerr << "Error" << std::endl;
                return;
            }
            operationCount++;
            _result = calculate(input[i]);
        }
    }
    printResult();
}

void RPN::printResult(){
    if (numberCount - operationCount != 1){
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << _result << std::endl;
}

int RPN::calculate(char op){
    int right = _numbers.top();
    _numbers.pop();
    int left = _numbers.top();
    _numbers.pop();
    int result;

    switch (op){
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            if (right == 0){
                std::cerr << "Error: Division by zero" << std::endl;
                _numbers.push(left);
                _numbers.push(right);
                exit(1);
            }
            result = left / right;
            break;
        default:
            std::cerr << "Error: Unknown operator" << op << std::endl;
            _numbers.push(left);
            _numbers.push(right);
            exit(1);
    }
    _numbers.push(result);
    return result;
}