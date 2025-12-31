#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BOLD    "\033[1m"

#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

struct Input
{
    std::string date;
    double value;
    double result;
};

class BitcoinExchange {
    private:
        std::map<std::string, double> _data;
        double getResult(const std::string& date, double value);
    public:
        BitcoinExchange();
        ~BitcoinExchange();

        void loadData(const std::string& filename);
        void loadInput(const std::string& filename);
        void printResult(Input& input);
        static bool isValidDate(const std::string& date);
        static void openFile(const std::ifstream& file);
        static double isValidValue(const std::string& value);

        class InvalidFileException : public std::exception{
            public:
                const char* what() const throw() {
                    return "Error: Invalid file";
                }
        };
        class DateNotFoundException : public std::exception{
            public:
            const char* what() const throw() {
                return "Error: Date not found in data";
            }
        };
};



#endif