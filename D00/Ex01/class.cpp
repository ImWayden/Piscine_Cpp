/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:50:42 by wayden            #+#    #+#             */
/*   Updated: 2024/01/19 18:21:15 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "class.hpp"

PhoneBook::PhoneBook() : oldest(0){
	return;
}

PhoneBook::~PhoneBook(){
	return;
}

std::string PhoneBook::limiter(const std::string& str, size_t maxLength) const
{
	return (str.length() > maxLength) ? str.substr(0, maxLength - 1) + '.' : str;
}

void PhoneBook::print_contact(Contact contact) const
{
	std::cout << "First Name      : " << contact.Info[FIRSTNAME] << std::endl;
	std::cout << "Last Name       : " << contact.Info[LASTNAME] << std::endl;
	std::cout << "NickName        : " << contact.Info[NICKNAME] << std::endl;
	std::cout << "Phone Number    : " << contact.Info[PHONENUMBER] << std::endl;
	std::cout << "Darkest Secret  : " << contact.Info[DARKESTSECRET] << std::endl;
}


void PhoneBook::search() const 
{
	const std::string constante[] = {"index", "first name", "last name", "nickname"};
	std::string UserInput;
	int i = 0;
	int valid = 0;
	int index;
	
	std::cout << std::setw(10) << PhoneBook::limiter(constante[0], 10) << "|" << PhoneBook::limiter(constante[1], 10) << "|";
	std::cout << std::setw(10) << PhoneBook::limiter(constante[2], 10) << "|" << std::setw(10) << PhoneBook::limiter(constante[3], 10);
	std::cout << std::endl;
	while(i < 8)
	{
		if(this->array[i].notempty)
		{
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << PhoneBook::limiter(this->array[i].Info[FIRSTNAME], 10) << "|" ;
			std::cout << std::setw(10) << PhoneBook::limiter(this->array[i].Info[LASTNAME], 10) << "|" ;			
			std::cout << std::setw(10) << PhoneBook::limiter(this->array[i].Info[NICKNAME], 10) << std::endl;
			valid++;		
		}
		i++;
	}
	if(valid)
	{
		std::cout << "Index : ";
		std::getline(std::cin, UserInput);
		std::cout << std::endl;
		index = std::atoi(UserInput.c_str());
		if(!isnum(UserInput) || index > valid || UserInput.empty() || index < valid)
			std::cout << "Index Invalide" << std::endl << "Retour au menu précédent" << std::endl;
		else
			this->print_contact(this->array[index]);
	}
	else
		std::cout << "Aucun contact enregistré, retour au menu précédent" << std::endl;
}

void PhoneBook::get_contact()
{	
	std::cout << "First Name      : ";
	std::getline(std::cin, this->array[this->oldest].Info[FIRSTNAME]);
	std::cout << "Last Name       : ";
	std::getline(std::cin, this->array[this->oldest].Info[LASTNAME]);
	std::cout << "NickName        : ";
	std::getline(std::cin, this->array[this->oldest].Info[NICKNAME]);
	std::cout << "Phone Number    : ";
	std::getline(std::cin, this->array[this->oldest].Info[PHONENUMBER]);
	std::cout << "Darkest Secret  : ";
	std::getline(std::cin, this->array[this->oldest].Info[DARKESTSECRET]);
	std::cout << "Contact added" << std::endl << std::endl;
	this->array[this->oldest].notempty++;
	if(this->oldest == 7)
		this->oldest = 0;
	else
		this->oldest++;
}

Contact::Contact() : notempty(0)
{
	return;
}

Contact::~Contact()
{
	return;	
}