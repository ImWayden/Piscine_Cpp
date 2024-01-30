/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:38 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 04:41:40 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "headers/Includes.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {
	std::cout << "WrongCat " << CONSTRUCTOR << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat& from) : WrongAnimal(from) {
	std::cout << "WrongCat Copy " << CONSTRUCTOR << std::endl;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat " << DESTRUCTOR << std::endl;
}

void WrongCat::makeSound( void ) const{
	std::cout << "Miaou Miaou !" << std::endl;
}
