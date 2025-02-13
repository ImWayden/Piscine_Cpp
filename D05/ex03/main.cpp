/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:07:37 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 02:54:56 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

int main(void)
{
	{
    	std::cout << "Test du constructeur par défaut:" << std::endl;
    	ShrubberyCreationForm b1;
    	std::cout << b1;
	
    	std::cout << "\n\nTest du constructeur avec paramètres:" << std::endl;
    	ShrubberyCreationForm b2("TargetA");
    	std::cout << b2;
	
    	std::cout << "\n\nTest du constructeur de copie:" << std::endl;
    	ShrubberyCreationForm b3 = b2;
    	std::cout << b3;
	
    	std::cout << "\n\nTest de l'opérateur d'assignation:" << std::endl;
    	ShrubberyCreationForm b4("TargetB");
    	b4 = b2;
    	std::cout << b4 << std::endl;
	}
	{
    	std::cout << "Test du constructeur par défaut:" << std::endl;
    	PresidentialPardonForm b1;
    	std::cout << b1;
	
    	std::cout << "\n\nTest du constructeur avec paramètres:" << std::endl;
    	PresidentialPardonForm b2("TargetA");
    	std::cout << b2;
	
    	std::cout << "\n\nTest du constructeur de copie:" << std::endl;
    	PresidentialPardonForm b3 = b2;
    	std::cout << b3;
	
    	std::cout << "\n\nTest de l'opérateur d'assignation:" << std::endl;
    	PresidentialPardonForm b4("TargetB");
    	b4 = b2;
    	std::cout << b4 << std::endl;
	}
	{
    	std::cout << "Test du constructeur par défaut:" << std::endl;
    	RobotomyRequestForm b1;
    	std::cout << b1;
	
    	std::cout << "\n\nTest du constructeur avec paramètres:" << std::endl;
    	RobotomyRequestForm b2("TargetA");
    	std::cout << b2;
	
    	std::cout << "\n\nTest du constructeur de copie:" << std::endl;
    	RobotomyRequestForm b3 = b2;
    	std::cout << b3;
	
    	std::cout << "\n\nTest de l'opérateur d'assignation:" << std::endl;
    	RobotomyRequestForm b4("TargetB");
    	b4 = b2;
    	std::cout << b4 << std::endl;
	}
	std::cout << "\nTest Sign" << std::endl;
	{
		Bureaucrat Jhonny = Bureaucrat("Jhonny", 1);
		Bureaucrat Fidgy = Bureaucrat("Fidgy", 25);
		Bureaucrat Bob = Bureaucrat("Bob", 75);
		Bureaucrat Billy = Bureaucrat("Billy", 150);
		try{
			ShrubberyCreationForm a1("Mokoko");
			Billy.signForm(a1);
			Billy.executeForm(a1);
			Bob.signForm(a1);
			Bob.executeForm(a1);
			Fidgy.signForm(a1);
			Fidgy.executeForm(a1);
			Jhonny.signForm(a1);
			Jhonny.executeForm(a1);
			std::cout << std::endl;
			
			RobotomyRequestForm a2("Bender");
			Billy.signForm(a2);
			Billy.executeForm(a2);
			Bob.signForm(a2);
			Bob.executeForm(a2);
			Fidgy.signForm(a2);
			Fidgy.executeForm(a2);
			Jhonny.signForm(a2);
			Jhonny.executeForm(a2);
			std::cout << std::endl;
			
			PresidentialPardonForm a3("Le Captain Jack");
			Billy.signForm(a3);
			Billy.executeForm(a3);
			Bob.signForm(a3);
			Bob.executeForm(a3);
			Fidgy.signForm(a3);
			Fidgy.executeForm(a3);
			Jhonny.signForm(a3);
			Jhonny.executeForm(a3);
			std::cout << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
	}
	
}
