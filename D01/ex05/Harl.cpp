/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:02:57 by wayden            #+#    #+#             */
/*   Updated: 2024/01/23 18:22:29 by wayden           ###   ########.fr       */
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
	(this->*functions[this->hash(level)])();
}