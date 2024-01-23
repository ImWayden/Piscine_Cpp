/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:57:35 by wayden            #+#    #+#             */
/*   Updated: 2024/01/23 19:27:59 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"




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
		if(input == "EXIT")
			break;
		karen.complain(input);;
	}
	return 0;
}