#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }

    RPN rpn;
    std::string expression = argv[1];
    rpn.acceptInput(expression);
    // Further implementation would go here to evaluate the RPN expression

    return 0;
}