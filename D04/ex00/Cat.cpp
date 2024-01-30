/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:38 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 04:25:41 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "headers/Includes.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Cat " << CONSTRUCTOR << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat& from) : Animal(from) {
	std::cout << "Cat Copy " << CONSTRUCTOR << std::endl;
}

Cat::~Cat( void ) {
	std::cout << "Cat " << DESTRUCTOR << std::endl;
}

void Cat::makeSound( void ) const{
	std::cout << "Miaou Miaou !" << std::endl;
}
