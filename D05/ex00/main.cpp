/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:07:37 by wayden            #+#    #+#             */
/*   Updated: 2025/02/07 23:50:03 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

int main(void)
{
	{
    	std::cout << "Test du constructeur par défaut:" << std::endl;
    	Bureaucrat b1;
    	std::cout << b1;
	
    	std::cout << "\n\nTest du constructeur avec paramètres:" << std::endl;
    	Bureaucrat b2("Billy", 5);
    	std::cout << b2;
	
    	std::cout << "\n\nTest du constructeur de copie:" << std::endl;
    	Bureaucrat b3 = b2;
    	std::cout << b3;
	
    	std::cout << "\n\nTest de l'opérateur d'assignation:" << std::endl;
    	Bureaucrat b4("Jhonny", 150);
    	b4 = b2;
    	std::cout << b4 << std::endl;
	}
	std::cout << "\nTest In Limit" << std::endl;
	{
		try{
			Bureaucrat Jhonny = Bureaucrat("Jhonny", 1);
			std::cout << Jhonny << std::endl;
			Bureaucrat Billy = Bureaucrat("Billy", 150);
			std::cout << Billy << std::endl;
		} catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
	}
	std::cout << "\nTest \"Smaller\" Limit" << std::endl;
	{
		try{
			Bureaucrat Jhonny = Bureaucrat("Jhonny", 5);
			std::cout << Jhonny << std::endl;
			Bureaucrat Billy = Bureaucrat("Billy", 0);
			std::cout << Billy;
		} catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
	}
	std::cout << "\nTest \"Higher\" Limit" << std::endl;
	{
		try{
			Bureaucrat Jhonny = Bureaucrat("Jhonny", 150);
			std::cout << Jhonny << std::endl;
			Bureaucrat Billy = Bureaucrat("Billy", 151);
			std::cout << Billy << std::endl;
		} catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
	}
	std::cout << "\nTest Decrement Grade" << std::endl;
	{
		try{
			Bureaucrat Jhonny = Bureaucrat("Jhonny", 1);
			for (int i = 0;  i < 152; i++)
			{
				Jhonny.decrementGrade();
				std::cout << Jhonny << std::endl;
			}
		} catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
	}
	std::cout << "\nTest Increment Grade" << std::endl;
	{
		try{
			Bureaucrat Jhonny = Bureaucrat("Jhonny", 150);
			for (int i = 0;  i < 152; i++)
			{
				Jhonny.incrementGrade();
				std::cout << Jhonny << std::endl;
			}
				
		} catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
	}
}
