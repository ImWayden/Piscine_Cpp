/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:57 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 16:26:46 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "headers/Includes.hpp"

Animal::Animal( void ) : type("canard") {
	std::cout << "Animal " << CONSTRUCTOR << std::endl;
}

Animal::Animal(Animal& from) : type(from.type) {
	std::cout << "Animal Copy " << CONSTRUCTOR << std::endl;
}

Animal::~Animal( void ) {
	std::cout << "Animal " << DESTRUCTOR << std::endl;
}

void Animal::makeSound( void ) const{
	std::cout << "Coin Coin !" << std::endl;
}

std::string Animal::getType( void ) const{
	return this->type;
}
Animal& Animal::operator=(const Animal &from)
{
	this->type = from.type;
	return *this;
}