/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:42:35 by wayden            #+#    #+#             */
/*   Updated: 2025/04/29 21:07:12 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"


struct ParsedData {
    std::string date;
    float value;
};

bool parseFormat1(const std::string& input, ParsedData& result) {
    if (input.size() < 11) return false;
    
    for (int i = 0; i < 10; ++i) {
        if ((i == 4 || i == 7) && input[i] != '-') return false;
        if (i != 4 && i != 7 && !isdigit(input[i])) return false;
    }
    
    if (input[10] != ',') return false;
    
    char* endPtr;
    float value = std::strtof(input.c_str() + 11, &endPtr);
    if (*endPtr != '\0') return false;
    
    result.date = input.substr(0, 10);
    result.value = value;
    return true;
}

bool parseFormat2(const std::string& input, ParsedData& result) {
    if (input.size() < 13) return false;
    
    for (int i = 0; i < 10; ++i) {
        if ((i == 4 || i == 7) && input[i] != '-') return false;
        if (i != 4 && i != 7 && !isdigit(input[i])) return false;
    }
    
    if (input[10] != ' ' || input[11] != '|' || input[12] != ' ') return false;
    
    char* endPtr;
    float value = std::strtof(input.c_str() + 13, &endPtr);
    if (*endPtr != '\0') return false;
    
    result.date = input.substr(0, 10);
    result.value = value;
    return true;
}

BitcoinExchange::BitcoinExchange(std::string filepath)
{
	std::string		line;
	std::ifstream	file(filepath.c_str());
	
	if(!file)
		throw std::exception();
	std::getline(file, line);//skip the first line
	while(std::getline(file, line))
	{
		ParsedData parsedline;
		if (parseFormat1(line, parsedline)) 
		{
			if (data.find(parsedline.date) != data.end())
				std::cerr << "Warning: Duplicate entry for date " << parsedline.date << " ignored." << std::endl;
			else
				data[parsedline.date] = parsedline.value;
		}
		else 
			std::cerr << "Data invalid Format: " << line << std::endl;
	}
}

float BitcoinExchange::getClosestValue(std::string date)
{
	   std::map<std::string, float>::iterator it = data.lower_bound(date);
    
	   if (it == data.end()) {
		   --it;
		   return it->second;
	   }
	   
	   if (it->first == date) {
		   return it->second;
	   }
	   
	   std::map<std::string, float>::const_iterator prev_it = it;
	   if (it != data.begin()) {
		   --prev_it;
	   }
   
	   int diffPrev = std::abs(static_cast<int>(date.compare(prev_it->first)));
	   int diffCurr = std::abs(static_cast<int>(date.compare(it->first)));

	   if (diffPrev <= diffCurr) {
		   return prev_it->second;
	   } else {
		   return it->second;
	   }
}


bool BitcoinExchange::checkValue(float &value)
{
	if(value < 0)
		return (std::cout << "Error : not a positive number" << std::endl, false);
	else if(value >= static_cast<float>(std::numeric_limits<int>::max()))
		return (std::cout << "Error :too large a number" << std::endl, false);
	return true;
}


void BitcoinExchange::exchange(std::string filepath)
{
	std::string		line;
	std::ifstream	file(filepath.c_str());

	if(!file)
		throw std::exception();
	std::getline(file, line);//skip the first line idk if i should tho
	while(std::getline(file, line))
	{
		ParsedData parsedline;
		if (parseFormat2(line, parsedline))
		{
			float			value = parsedline.value;
			std::string		date = parsedline.date;

			if(checkValue(value))
				std::cout << date << " => " << value << " = " << static_cast<float>(value * getClosestValue(date)) << std::endl;
		}
		else 
			std::cerr << "Input invalid Format: " << line << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange(){};
/*
BitcoinExchange::BitcoinExchange(std::string filepath = "./res/data.csv")
{
	std::string		line;
	std::ifstream	file(filepath);
	std::regex 		format(R"(^(\d{4}-\d{2}-\d{2}),(-?\d+(\.\d+)?)$)"); // YYYY-MM-DD,float
    std::smatch 	match;
	
	if(!file)
		throw std::exception();
	std::getline(file, line);//skip the first line
	while(std::getline(file, line))
	{
		if (std::regex_match(line, match, format)) 
            data[match[1]] = std::stof(match[2]);
        else 
            std::cerr << "Data invalid Format: " << line << std::endl;
	}
}
*/

/*
void BitcoinExchange::exchange(std::string filepath)
{
	std::string		line;
	std::ifstream	file(filepath);
	std::regex 		format(R"(^(\d{4}-\d{2}-\d{2})\s*\|\s*(-?\d+(\.\d+)?)$)"); // YYYY-MM-DD | float
    std::smatch 	match;

	if(!file)
		throw std::exception();
	std::getline(file, line);//skip the first line idk if i should tho
	while(std::getline(file, line))
	{
		if (std::regex_match(line, match, format))
		{
			float			value = std::atof(static_cast<std::string>(match[2]).c_str());
			std::string		date = match[1];
			if(checkValue(value))
				std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << static_cast<float>(value * getClosestValue(date)) << std::endl;
		}
		else 
			std::cerr << "Input invalid Format: " << line << std::endl;
	}
}
*/