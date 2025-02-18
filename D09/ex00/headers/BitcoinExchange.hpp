/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:28:29 by wayden            #+#    #+#             */
/*   Updated: 2025/02/18 04:43:50 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include "includes.hpp"

class BitcoinExchange
{
public:
	//BitcoinExchange();
	BitcoinExchange(std::string filepath = "./res/data.csv");
	BitcoinExchange(const BitcoinExchange& from);
	~BitcoinExchange();
		
	void exchange(std::string filepath);
	
	
	BitcoinExchange& operator=(const BitcoinExchange& from);
private:
	std::map<std::string, float> data;
	bool checkValue(float &value);
	float getClosestValue(std::string date);
};



#endif