/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:57 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 04:40:23 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "headers/Includes.hpp"

WrongAnimal::WrongAnimal( void ) : type("canard") {
	std::cout << "WrongAnimal " << CONSTRUCTOR << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& from) : type(from.type) {
	std::cout << "WrongAnimal Copy " << CONSTRUCTOR << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal " << DESTRUCTOR << std::endl;
}

void WrongAnimal::makeSound( void ) const{
	std::cout << "Coin Coin !" << std::endl;
}

std::string WrongAnimal::getType( void ) const{
	return this->type;
}