/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiabi <leticiabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:29:52 by hguo              #+#    #+#             */
/*   Updated: 2026/03/07 08:47:34 by leticiabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;
	
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t sep = line.find(',');
		if (sep != std::string::npos) {
			std::string date = line.substr(0, sep);
			float rate = static_cast<float>(atof(line.substr(sep + 1).c_str()));
			_database[date] = rate;
		}
	}
	file.close();
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	
	int y, m, d;
	std::stringstream ss_y(date.substr(0, 4));
	std::stringstream ss_m(date.substr(5, 2));
    std::stringstream ss_d(date.substr(8, 2));
    
    if (!(ss_y >> y) || !(ss_m >> m) || !(ss_d >> d))
		return false;

    if (y < 2008 || m < 1 || m > 12 || d < 1 || d > 31)
		return false;
    
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		return false;
    if (m == 2) {
        bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (d > (isLeap ? 29 : 28))
			return false;
    }
    return true;
}

bool    BitcoinExchange::isValidValue (const std::string& valueStr, float& value) {
    if (valueStr.empty())
        return false;
    
    char    *end;
    double val = std::strtod(valueStr.c_str(), &end);
    // pour éviter les chars invalid
    
    if (*end != '\0') {
        std::cout << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    if (val < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }

    value = static_cast<float>(val);
    return true;
}

void    BitcoinExchange::trim(std::string& s) {
    size_t  first = s.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        s = "";
        return;
    }
    size_t last = s.find_last_not_of(" \t\r\n");
    s = s.substr(first, (last - first + 1));
}

void    BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.empty())
            continue ;
            
        size_t  sep = line.find('|');
        if (sep == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string dateStr = line.substr(0, sep);
        std::string valStr = line.substr(sep + 1);

        trim(dateStr);
        trim(valStr);

        if (!isValidDate(dateStr)) {
            std::cout << "Error: bad input => " << dateStr << std::endl;
            continue;
        }

        float val;
        if (!isValidValue(valStr, val)) {
            continue;
        }

		std::map<std::string, float>::iterator it = _database.lower_bound(dateStr);
        if (it == _database.end() || it->first != dateStr) {
            if (it == _database.begin()) {
                std::cout << "Error: date too early => " << dateStr << std::endl;
                continue;
            }
            --it;
        }
        std::cout << dateStr << " => " << val << " = " << (val * it->second) << std::endl;
    }
}
