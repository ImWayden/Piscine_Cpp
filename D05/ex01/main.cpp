/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:07:37 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 00:48:09 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

int main(void)
{
	{
    	std::cout << "Test du constructeur par défaut:" << std::endl;
    	Form b1;
    	std::cout << b1;
	
    	std::cout << "\n\nTest du constructeur avec paramètres:" << std::endl;
    	Form b2("Contract B2", false, 1, 1);
    	std::cout << b2;
	
    	std::cout << "\n\nTest du constructeur de copie:" << std::endl;
    	Form b3 = b2;
    	std::cout << b3;
	
    	std::cout << "\n\nTest de l'opérateur d'assignation:" << std::endl;
    	Form b4("Contract B4", true, 1, 1);
    	b4 = b2;
    	std::cout << b4 << std::endl;
	}
	std::cout << "\nTest In Limit" << std::endl;
	{
		try{
			Form a1("Contract A1", false, 1, 1);
			std::cout << a1 << std::endl;
			Form a2("Contract A2", false, 1, 150);
			std::cout << a2 << std::endl;
			Form a3("Contract A3", false, 150, 1);
			std::cout << a3 << std::endl;
			Form a4("Contract A4", false, 150, 150);
			std::cout << a4 << std::endl;
			
			Form b1("Contract B1", true, 1, 1);
			std::cout << b1 << std::endl;
			Form b2("Contract B2", true, 1, 150);
			std::cout << b2 << std::endl;
			Form b3("Contract B3", true, 150, 1);
			std::cout << b3 << std::endl;
			Form b4("Contract B4", true, 150, 150);
			std::cout << b4 << std::endl;
			
		} catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
	}
	std::cout << "\nTest \"Smaller\" Limit" << std::endl;
	{
		try{
			Form a1("Contract A1", false, 1, 1);
			std::cout << a1 << std::endl;
			Form a2("Contract A2", false, 0, 1);
			std::cout << a1 << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
		try{
			Form b1("Contract B1", false, 1, 1);
			std::cout << b1 << std::endl;
			Form b2("Contract B2", false, 1, 0);
			std::cout << b2 << std::endl;
		} catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
	}
	std::cout << "\nTest \"Higher\" Limit" << std::endl;
	{
		try{
			Form a1("Contract A1", false, 150, 150);
			std::cout << a1 << std::endl;
			Form a2("Contract A2", false, 151, 150);
			std::cout << a1 << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
		try{
			Form b1("Contract B1", false, 150, 150);
			std::cout << b1 << std::endl;
			Form b2("Contract B2", false, 150, 151);
			std::cout << b2 << std::endl;
		} catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
	}
	std::cout << "\nTest Sign" << std::endl;
	{
		Bureaucrat Jhonny = Bureaucrat("Jhonny", 1);
		Bureaucrat Bob = Bureaucrat("Bob", 75);
		Bureaucrat Billy = Bureaucrat("Billy", 150);
		try{
			Form a1("Contract A1", false, 150, 150);
			Billy.signForm(a1);
			Bob.signForm(a1);
			Jhonny.signForm(a1);
			std::cout << std::endl;
			
			Form a2("Contract A2", false, 150, 25);
			Billy.signForm(a2);
			Bob.signForm(a2);
			Jhonny.signForm(a2);

			std::cout << std::endl;
			Form a3("Contract A3", false, 75, 150);
			Billy.signForm(a3);
			Bob.signForm(a3);
			Jhonny.signForm(a3);

			std::cout << std::endl;
			Form a4("Contract A4", false, 25, 150);
			Billy.signForm(a4);
			Bob.signForm(a4);
			Jhonny.signForm(a4);
		}
		catch(const std::exception& e){
			std::cerr << "Une exception a été capturée: " << e.what() << std::endl;
		}
	}
}
