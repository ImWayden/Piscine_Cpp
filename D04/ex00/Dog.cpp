/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:03 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 04:25:48 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "headers/Includes.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "Dog " << CONSTRUCTOR << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog& from) : Animal(from) {
	std::cout << "Dog Copy " << CONSTRUCTOR << std::endl;
}

Dog::~Dog( void ) {
	std::cout << "Dog " << DESTRUCTOR << std::endl;
}

void Dog::makeSound( void ) const{
	std::cout << "Wouf Wouf !" << std::endl;
}
