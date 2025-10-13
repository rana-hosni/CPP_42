
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>


int main() {

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::cout << '['
              << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday
              << '_'
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "] ";
    return 0;
}