#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _exchangeRates(copy._exchangeRates)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		this->_exchangeRates = copy._exchangeRates;
	}
	return (*this);
}

void BitcoinExchange::loadDataBase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date, value;
		if (!std::getline(iss, date, ',') || !std::getline(iss, value)) {
			std::cerr << "Error: invalid line format in file." << std::endl;
			continue;
		}
		if (!isValidDate(date) || !isValidValue(value, true)) {
			continue;
		}
		char *endptr;
		float val = std::strtof(value.c_str(), &endptr);
		if (*endptr != '\0') {
			std::cerr << "Error: invalid number format in file." << std::endl;
			continue;
		}
		this->_exchangeRates[date] = val;
	}
	file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: invalid date format: " << date << std::endl;
        return false;
    }

    int year, month, day;
    if (std::sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3) {
        std::cerr << "Error: invalid date format: " << date << std::endl;
        return false;
    }

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        std::cerr << "Error: invalid date value: " << date << std::endl;
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        std::cerr << "Error: invalid day for month: " << date << std::endl;
        return false;
    }

    if (month == 2) {
        bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (leap ? 29 : 28)) {
            std::cerr << "Error: invalid day for February: " << date << std::endl;
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value, bool isRate) const
{
	char *endptr;
	float val = std::strtof(value.c_str(), &endptr);
	if (*endptr != '\0' || val < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (!isRate && val > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	if (!isRate && val < 0.01) {
		std::cerr << "Error: too small a number." << std::endl;
		return false;
	}
	return true;
}

float BitcoinExchange::getRateFromDate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = this->_exchangeRates.lower_bound(date);
	if (it != this->_exchangeRates.end() && it->first == date) {
		return it->second;
	}
	if (it == this->_exchangeRates.begin()) {
		std::cerr << "Error: no earlier date found for: " << date << std::endl;
		return -1;
	}
	--it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t sep = line.find('|');
		if (sep == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, sep));
		std::string value = trim(line.substr(sep + 1));
		if (date.empty()) {
			std::cerr << "Error: empty date." << std::endl;
			continue;
		}

		if (value.empty()) {
			std::cerr << "Error: empty value for date: " << date << std::endl;
			continue;
		}

		if (!isValidDate(date) || !isValidValue(value, false)) {
			continue;
		}

		char *endptr;
		float val = std::strtof(value.c_str(), &endptr);
		if (*endptr != '\0') {
			std::cerr << "Error: invalid value: " << value << std::endl;
			continue;
		}

		float rate = getRateFromDate(date);
		if (rate >= 0)
			std::cout << date << " => " << value << " = " << rate * val << std::endl;
	}
	file.close();
}

std::string BitcoinExchange::trim(const std::string &str) const
{
	size_t first = str.find_first_not_of(" \t");
	size_t last = str.find_last_not_of(" \t");
	if (first == std::string::npos || last == std::string::npos)
		return "";
	return str.substr(first, last - first + 1);
}
