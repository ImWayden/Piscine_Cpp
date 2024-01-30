/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:03 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 16:49:04 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "headers/Includes.hpp"

Dog::Dog( void ) : Animal() {std::cout << "Dog " << CONSTRUCTOR << std::endl;
	this->ideas = new Brain;
	this->type = "Dog";
}

Dog::Dog(Dog& from) : Animal(from) {std::cout << "Dog Copy " << CONSTRUCTOR << std::endl;
	this->ideas = new Brain(*from.ideas);
}

Dog::~Dog( void ) {std::cout << "Dog " << DESTRUCTOR << std::endl;
	delete this->ideas;
}

void Dog::makeSound( void ) const{
	std::cout << "Wouf Wouf !" << std::endl;
}

Dog& Dog::operator=(const Dog &from)
{
	if (this != &from)
		*this = from;
	return *this;
}