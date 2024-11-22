#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy){
    _map = copy._map;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &copy){
    if (this != &copy){
        _map = copy._map;
    }
    return (*this);
}

bool isLeapYear(int year){
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool validInput(std::string line, size_t pos){
    int             year;
    int             month;
    int             day;
    float           value;

    if (pos == std::string::npos)
        return false;
    year = std::atoi(line.substr(0, 4).c_str());
    month = std::atoi(line.substr(5, 2).c_str());
    day = std::atoi(line.substr(8, 2).c_str());
    if (year < 2009 || (month < 1 || month > 12) || (day < 1 || day > 31))
        return false;
    if ((isLeapYear(year) && month == 2 && day > 29) || (!isLeapYear(year) && month == 2 && day > 28))
        return false;
    if (line[4] != '-' || line[7] != '-'){
        return false;
    }
    if (line.substr(13).empty()){
        return false;
    }
    value = std::atof(line.substr(13).c_str());
    if (value == 0 && line.substr(13).length() != 0)
        return false;
    return true;
}

void    BitcoinExchange::exchanger(char *fileName){
    double          value;
    std::string     line;

    std::ifstream   input(fileName);
    if (!input){
        std::cerr << "Failed to open file." << std::endl;
    }
    std::getline(input, line);
    if (line != "date | value")
        std::cerr << "First line error" << std::endl; 
    while (std::getline(input, line)){
        size_t pos = line.find(" | ");
        if (!validInput(line, pos)){
            std::cerr << "Error: bad input => " << line.substr(0, pos) << std::endl;
        }
        else{
            value = std::atof(line.substr(13).c_str());
            if (value < 0){
                std::cerr << "Error: not a positive number." << std::endl;
            }
            else if (value > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else{
                std::map<std::string, float>::iterator it = _map.upper_bound(line.substr(0, 10));
                if (it == _map.begin()){
                    std::cout << "No element not possible" << std::endl;
                }
                else{
                    --it;
                    std::cout << line.substr(0, 10) << " => " << line.substr(13) << " = " << value * it->second << std::endl;  
                }
            }
        }
    }
    input.close();
}

void    BitcoinExchange::saveData(){
    char            *end;
    float           rate;
    std::string     dataLine;

    std::ifstream   data("./data.csv");
    getline(data, dataLine);
    if (dataLine != "date,exchange_rate")
        std::cerr << "Error: first line" << std::endl;
    while (getline(data, dataLine)){
        rate = std::strtof(dataLine.substr(11).c_str(), &end);
        _map[dataLine.substr(0, 10)] = rate;
    }
    data.close();
    return ;
}