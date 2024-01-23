/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:57:35 by wayden            #+#    #+#             */
/*   Updated: 2024/01/23 18:34:17 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"


bool check(std::string input){
	return(input == "INFO" || input == "DEBUG" || input == "ERROR" || input == "WARNING" || input == "EXIT");
}

int main(int argc, char **argv)
{
	Harl karen;
	std::string input;
	
	while(1)
	{
		std::cout << "Input : "; 
		getline(std::cin, input);
		if(std::cin.eof())
		{
			std::cin.clear();
            clearerr(stdin);
			std::cout << std::endl;
		}
		if (input.empty() || !check(input))
		{
			std::cout << "invalide input." << std::endl\
			<< "LEVEL: DEBUG, INFO, ERROR, WARNING" << std::endl;
			continue;
		}
		else if(input == "EXIT")
			break;
		karen.complain(input);;
	}
	return 0;
}