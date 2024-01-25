/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:48:14 by wayden            #+#    #+#             */
/*   Updated: 2024/01/25 14:31:04 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"
//constructeur
Fixed::Fixed() : value(0) {
	std::cout << "Default " << CONSTRUCTOR << std::endl;
}

//coy constructor
Fixed::Fixed(const Fixed& from) {
	std::cout << "Copy " << CONSTRUCTOR << std::endl;
	*this = from;
}

//destructeur
Fixed::~Fixed() {
	std::cout << DESTRUCTOR << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits " << MEMBER << std::endl;
    return this->value;
}
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits " << MEMBER << std::endl;
    this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& from) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &from)
        this->value = from.getRawBits();
    return *this;
}