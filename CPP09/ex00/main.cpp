#include "BitcoinExchange.hpp"

void validateInputFile(std::string file) {
    try{
        if (file.substr((file.length() - 4)) != ".txt"){
            std::cerr << RED << "Error:" << RESET << " Input file must be a .txt file" << std::endl;
            exit(1);
        }
        try{
            std::ifstream infile(file.c_str());
            if (!infile.good()){
                std::cerr << RED << "Error:" << RESET << " Input file does not exist" << std::endl;
                exit(1);
            }
            if (infile.peek() == std::ifstream::traits_type::eof()) {
                std::cerr << RED << "Error:" << RESET << " Input file is empty" << std::endl;
                exit(1);
            }
            infile.close();
        }
        catch(...){
            std::cerr << RED << "Error:" << RESET << " Input file does not exist" << std::endl;
            exit(1);
        }
    }
    catch(...){
        std::cerr << RED << "Error:" << RESET << " Input file must be a .txt file" << std::endl;
        exit(1);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << RED << "Error:" << RESET << " Add input file"<< std::endl;
        return 1;
    }
    
    validateInputFile(argv[1]);
    std::string inputFile = argv[1];
    BitcoinExchange exchange;
    try{
        exchange.loadData("data.csv");
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    exchange.loadInput(inputFile);
    // Further implementation goes here

    return 0;
}