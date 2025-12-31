#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    BitcoinExchange::openFile(file);
    std::string line;
    std::getline(file, line); // Skip header line
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        size_t comma = line.find(',');
        if (comma != std::string::npos) {
            std::string date = line.substr(0, comma);
            if (!BitcoinExchange::isValidDate(date)) {
                std::cerr << "Invalid date format: " << date << std::endl;
                continue; // Skip invalid entries
            }
            // std::cout << "Date: " << date << std::endl;
            std::string rateString = line.substr(comma + 1);
            // std::cout << "Rate string: " << rate << std::endl;
            std::istringstream ss(rateString);
            double rate;
            ss >> rate;
            if (ss.fail() || !ss.eof()) {
                std::cerr << "Invalid rate format: " << rateString << std::endl;
                continue; // Skip invalid entries
            }
            _data[date] = rate;
        }
    }
    file.close();
    if (_data.empty()) {
        throw InvalidFileException();
    }
}

void BitcoinExchange::loadInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    BitcoinExchange::openFile(file);
    std::string line;
    std::getline(file, line); // Skip header line
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        Input _input;
        size_t separator = line.find(" | ");
        if (separator != std::string::npos) {
            _input.date = line.substr(0, separator);
            std::string valueString = line.substr(separator + 3);
            if (!BitcoinExchange::isValidDate(_input.date)) {
                std::cerr << RED << "Error:" << RESET << " invalid date => " << line << std::endl;
                continue;
            }
            if (valueString.empty()) {
                std::cerr << RED << "Error:" << RESET << " bad input => " << line << std::endl;
                continue;
            }
            _input.value = BitcoinExchange::isValidValue(valueString);
            if (_input.value == -1)
                continue;
            else{
                _input.result = getResult(_input.date, _input.value);
                if (_input.result != -1)
                    printResult(_input);
            }

        }
        else
            std::cerr << RED << "Error:" << RESET << " bad input => " << line << std::endl;
    }
    file.close();
}

void BitcoinExchange::openFile(const std::ifstream& file) {
    try{
        if (!file.is_open()) {
            throw InvalidFileException();
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}


bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    for (size_t i = 0; i < date.length(); i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(static_cast<unsigned char>(date[i]))) return false;
    }

    int month = std::atoi((date.substr(5, 2)).c_str());
    int day = std::atoi((date.substr(8, 2)).c_str());
    int year = std::atoi((date.substr(0, 4)).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0) {
        return false;
    }
    //leap year check
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        if (month == 2 && day > 29) {
            return false;
        }
    }
    else {
        if (month == 2 && day > 28) {
            return false;
        }
    }
    if (((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        return false;
    }
    return true;
}

double BitcoinExchange::isValidValue(const std::string& value){
    if (value[0] == '.' || value[value.length() - 1] == '.') {
        std::cerr << RED << "Error:" << RESET << " invalid value => " << value << std::endl;
        return -1; // Invalid format
    }
    if (value[0] == '-') {
        std::cerr << RED << "Error:" << RESET << " not a positive number." << std::endl;
        return -1;
    }
    std::istringstream ss(value);
    double val;
    ss >> val;
    if (ss.fail() || !ss.eof() ) {
        std::cerr << RED << "Error:" << RESET << " invalid value => " << value << std::endl;
        return -1; // Invalid format
    }
    if (val < 0.0) {
        std::cerr << RED << "Error:" << RESET << " not a positive number." << std::endl;
        return -1;
    }
    else if (val > 1000.0) {
        std::cerr << RED << "Error:" << RESET << " too large a number." << std::endl;
        return -1;
    }
    return val;
}

double BitcoinExchange::getResult(const std::string& date, double value){
    std::map<std::string, double>::iterator it = _data.find(date);
    double result;
    if (it != _data.end() && it->first == date){
        //Search for closest
        result = it->second * value;
    }
    else{
        try{

            it = _data.lower_bound(date);
            if (it == _data.begin() && it->first != date){
                throw DateNotFoundException();
            }
            else{
                --it;
                result = it->second * value;
            }
        }
        catch (const DateNotFoundException& e) {
            std::cerr << e.what() << std::endl;
            result = -1; // or handle the error as needed
        }
    }
    return result;
}

void BitcoinExchange:: printResult(Input& input) {
    std::cout << input.date << " => " << input.value << " = " << input.result << std::endl;
}