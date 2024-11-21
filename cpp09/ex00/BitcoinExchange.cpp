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

bool is_valid_input(std::string line){
    int year;
    int month;
    int day;

    year = std::atoi(line.substr(0, 4).c_str());
    month = std::atoi(line.substr(5, 2).c_str());
    day = std::atoi(line.substr(8, 2).c_str());
    if (year < 2009 || (month < 1 || month > 12) || (day < 1 || day > 31))
        return false;
    if ((isLeapYear(year) && month == 2 && day > 29) || (!isLeapYear(year) && month == 2 && day > 28))
        return false;
    if (line[4] != '-' || line[7] != '-' || line.substr(10, 3) != " | "){
        std::cerr << "Error" << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::validInputData(char *fileName){
    float           value;
    std::string     line;
    std::string     date;
    std::string     dataLine;

    std::ifstream   input(fileName);
    std::ifstream   data("./data.csv");
    if (!input || !data){
        std::cerr << "Failed to open file." << std::endl;
        return ;
    }
    std::getline(input, line);
    std::getline(data, dataLine);
    if (line != "date | value" || dataLine != "date,exchange_rate"){
        std::cerr << "First line error" << std::endl; 
    }
    while (getline(input, line)){
        if (!is_valid_input(line)){
            size_t pos = line.find(" | ");
            if (pos == std::string::npos){
                std::cerr << "Error: can not find delimeter" << std::endl; 
            }
            std::cerr << "Error: bad input => " << line.substr(0, pos) << std::endl;
        }
        std::stringstream ss(line.substr(13));
        date = line.substr(0, 9);
        ss >> value;
        _map[date] = value;
        //if (!(ss >> value)){
        //    std::cerr << "Error: Value error" << std::endl;
        //}

    }
    input.close();
    data.close();
}

void    BitcoinExchange::exchanger(){
    std::string     dataDate;
    std::string     dataLine;
    float           beforeRate;
    float           rate;
    char*           end;

    beforeRate = 0;
    std::ifstream   data("./data.csv");
    getline(data, dataLine);
    for (std::map<std::string, float>::iterator it = _map.begin(); it != _map.end(); ++it){
        if (it->second < 0){
            std::cerr << "Error: not a positive value." << std::endl; 
        }
        else if (it->second > 1000){
            std::cerr << "Error: too large value." << std::endl;
        }
        else{
            while (getline(data, dataLine)){
                dataDate = dataLine.substr(0, 9);
                rate = std::strtof(dataLine.substr(10).c_str(), &end);
                if (*end == '\0')
                {
                    std::cerr << "Error" << std::endl;
                    continue;
                }
                if (it->first == dataDate){
                    std::cout << it->first << " => " << it->second << " = " << it->second * rate << std::endl; 
                    break;
                }
                if (it->first > dataDate){
                    std::cout << it->first << " => " << it->second << " = " << it->second * beforeRate << std::endl; 
                    break;
                }
                beforeRate = rate;
            }
        }
    } 
}