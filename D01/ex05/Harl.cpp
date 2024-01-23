/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:02:57 by wayden            #+#    #+#             */
/*   Updated: 2024/01/23 19:29:32 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

Harl::Harl( void ) {}

Harl::~Harl( void ) {}

int Harl::hash(const std::string& str){
	int hashvalue = 0;
	int i = 0;
	for(char c : str)
	{
		hashvalue += static_cast<int>(c) + i;
		i++;
	}
	return ((hashvalue) % 4);	
}

bool Harl::check(std::string input){
	return(input == "INFO" || input == "DEBUG" || input == "ERROR" || input == "WARNING" || input == "EXIT");
}

void Harl::debug(){
	std::cout << HARL_DEBUG << std::endl;
}

void Harl::error(){
	std::cout << HARL_ERROR << std::endl;
}

void Harl::warning(){
	std::cout << HARL_WARNING << std::endl;
}

void Harl::info(){
	std::cout << HARL_INFO << std::endl;
}


void Harl::complain(std::string level)
{
	void (Harl::*functions[4])( void ) = {&Harl::error, &Harl::debug, &Harl::info, &Harl::warning};
	if (level.empty() || !Harl::check(level))
	{
		std::cout << "invalide input." << '\n'\
		<< "LEVEL: DEBUG, INFO, ERROR, WARNING" << std::endl;
	}
	else
		(this->*functions[this->hash(level)])();
}