#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <algorithm>

class BitcoinExchange {
	private:  
		std::map<std::string, float> _database;

		bool isValidDate(const std::string& date);
		bool isValidValue(const std::string& valueStr, float& value);
		void trim(std::string& s);

	public:  
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool loadDatabase(const std::string& filename);
		void processInput(const std::string& filename);
};

#endif