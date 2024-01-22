/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:50:42 by wayden            #+#    #+#             */
/*   Updated: 2024/01/22 17:02:12 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "First Name      : " << contact.getfirstname() << std::endl;
	std::cout << "Last Name       : " << contact.getlastname() << std::endl;
	std::cout << "NickName        : " << contact.getnickname() << std::endl;
	std::cout << "Phone Number    : " << contact.getphonenumber() << std::endl;
	std::cout << "Darkest Secret  : " << contact.getdarkestsecret() << std::endl;
}


void PhoneBook::search()
{
	const std::string constante[] = {"index", "first name", "last name", "nickname"};
	std::string UserInput;
	int i = 0;
	bool isempty;
	int valid = 0;
	int index;
	
	std::cout << std::setw(10) << PhoneBook::limiter(constante[0], 10) << "|" << PhoneBook::limiter(constante[1], 10) << "|";
	std::cout << std::setw(10) << PhoneBook::limiter(constante[2], 10) << "|" << std::setw(10) << PhoneBook::limiter(constante[3], 10);
	std::cout << std::endl;
	while(i < 8)
	{
		if(this->array[i].getempty())
		{
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << PhoneBook::limiter(this->array[i].getfirstname(), 10) << "|" ;
			std::cout << std::setw(10) << PhoneBook::limiter(this->array[i].getlastname(), 10) << "|" ;			
			std::cout << std::setw(10) << PhoneBook::limiter(this->array[i].getnickname(), 10) << std::endl;
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
		if(!isnum(UserInput) || index > valid || UserInput.empty() || index < 0)
			std::cout << "Index Invalide" << std::endl << "Retour au menu précédent" << std::endl;
		else
			this->print_contact(this->array[index]);
	}
	else
		std::cout << "Aucun contact enregistré, retour au menu précédent" << std::endl;
}

void PhoneBook::get_contact()
{	
	std::string input;
	
	std::cout << "First Name      : ";
	std::getline(std::cin, input);
	this->array[this->oldest].setfirstname(input);
	std::cout << "Last Name       : ";
	std::getline(std::cin, input);
	this->array[this->oldest].setlastname(input);
	std::cout << "NickName        : ";
	std::getline(std::cin, input);
	this->array[this->oldest].setnickname(input);
	std::cout << "Phone Number    : ";
	std::getline(std::cin, input);
	this->array[this->oldest].setphonenumber(input);
	std::cout << "Darkest Secret  : ";
	std::getline(std::cin, input);
	this->array[this->oldest].setdarkestsecret(input);
	std::cout << "Contact added" << std::endl << std::endl;
	this->array[this->oldest].setempty(1);
	if(this->oldest == 7)
		this->oldest = 0;
	else
		this->oldest++;
}

