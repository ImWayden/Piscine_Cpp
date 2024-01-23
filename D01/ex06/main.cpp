/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:57:35 by wayden            #+#    #+#             */
/*   Updated: 2024/01/23 19:31:25 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"


bool check(std::string input){
	return(input == "INFO" || input == "DEBUG" || input == "ERROR" || input == "WARNING");
}

int main(int argc, char **argv)
{
	Harl karen;
	if(argc != 2 || !argv[1])
		return(std::cout << "Usage : ./HarlFilter [LEVEL]" << std::endl, 1);
	else
		karen.complain(argv[1]);
	return 0;
}