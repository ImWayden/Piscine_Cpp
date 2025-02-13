/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:17:08 by wayden            #+#    #+#             */
/*   Updated: 2025/02/13 17:32:43 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

std::string Intern::forms[3] = {"shrubberycreation", "robotomyrequest", "presidentialpardon"};
const char* Intern::InvalidContract::what() const throw() { return "Invalid contract name!";}

Intern::Intern(void){}
Intern::Intern(const Intern& intern){(void)intern;}
Intern::~Intern(void){}

void normalizename(std::string& str) {
    size_t pos;
	std::string toignore[2] = {"contract", "form"};
	size_t j = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != ' ') {
            str[j++] = std::tolower(str[i]);
        }
    }
    str.resize(j); // Supprime les caractères en trop
	for(int i = 0; i < 2; i++)
	{
		while ((pos = str.find(toignore[i])) != std::string::npos) {
			str.erase(pos, toignore[i].length());
		}
    }
}

/*
** it's a bit disgusting since it creates each possible forms but it was easy to code so not gonna complain
** if i had more types of contract (and access to maps) i would just create a map with names as key and lambdas to create the forms
*/
AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* form[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	AForm* ret = NULL;
	normalizename(name);
	for(int i = 0; i < 3; i++)
	{
		if(Intern::forms[i] == name)
			ret = form[i];
		else
			delete form[i];
	}
	if(ret == NULL)
		throw InvalidContract();
	return ret;
}
Intern &Intern::operator=(const Intern &from){(void)from;return *this;}
