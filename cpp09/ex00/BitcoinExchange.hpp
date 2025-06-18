#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <iomanip>


class BitcoinExchange
{
	private:
		std::map<std::string, float> _exchangeRates;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void loadDataBase(const std::string &filename);
		bool isValidDate(const std::string &date) const;
		bool isValidValue(const std::string &value, bool isRate) const;
		bool isValidValue(const std::string &value) const;
		float getRateFromDate(const std::string &date) const;
		void processInput(const std::string &filename) const;
		std::string trim(const std::string &str) const;
};

#endif