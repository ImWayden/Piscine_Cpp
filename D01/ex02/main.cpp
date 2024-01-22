/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:50:32 by wayden            #+#    #+#             */
/*   Updated: 2024/01/22 17:05:19 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringSTR = &string;
	std::string& stringREF = string;

	std::cout << std::setw(35) << std::left << "adresse de la string:" << static_cast<void*>(&string) << std::endl\
	<< std::setw(36) <<"adresse stocké dans stringSTR:" << static_cast<void*>(stringSTR) << std::endl\
	<< std::setw(36) << "adresse stocké dans stringREF:" << static_cast<void*>(&stringREF) << std::endl;

	std::cout << std::setw(35) << std::left <<"valeur de la string:" << string << std::endl\
	<< std::setw(36) << "valeur stocké dans stringSTR:" << *stringSTR << std::endl\
	<< std::setw(36) << "valeur stocké dans stringREF:" << stringREF << std::endl;
}