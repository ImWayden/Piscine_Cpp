/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:48:14 by wayden            #+#    #+#             */
/*   Updated: 2024/01/25 19:29:05 by wayden           ###   ########.fr       */
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

/* voici ce que j'aurai préférer faire mais ca me donne 42.418 et non 42.4219 
sauf qu'en fait c'est a chier parceque je perd de l'information et que la manière la plus simple reste d'arrondir a une précision de 8bit
puisque la je supprime x bit d'informations pour n'en garder que 8 max 
Fixed::Fixed(const float raw){
	std::cout << "Float " << CONSTRUCTOR << std::endl;
	uint32_t rawBits;
	std::memcpy(&rawBits, &raw, sizeof(float));
	int exposant = ((rawBits >> 23) & 0xFF) - 127;
	uint32_t mantisse = rawBits & 0x7FFFFF;
	int intbits = ((1 << 23) | mantisse) >> (23 - exposant);
	int fracbits = mantisse >> (23 - exposant - this->nb_bits) & ((1 << this->nb_bits - 1);
	this->setRawBits(intbits << this->nb_bits | fracbits);
}
*/
Fixed::Fixed(const float raw) : value( roundf(raw * (1 << Fixed::nb_bits)) ){
	std::cout << "Float " << CONSTRUCTOR << std::endl;

}

Fixed::Fixed(const int raw){
	std::cout << "Int " << CONSTRUCTOR << std::endl;
	this->value = raw << this->nb_bits;
}
//destructeur
Fixed::~Fixed() {
	std::cout << DESTRUCTOR << std::endl;
}



//member function

int Fixed::getRawBits() const {
	//std::cout << "getRawBits " << MEMBER << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits " << MEMBER << std::endl;
    this->value = raw;
}

/*
** ((1 << this->nb_bits) - 1 creation d'un bitmask de la taille de nb_bits afin 
** de pouvoir par la suite extraire les bits de la partie fractionnaire
**
**	1 << n  = 0b100000 (place le bit 1 a la position n + 1)
**  ((1 << n) - 1) transformer 0b100000 en 0b11111 de la meme manière 
**  que 10000 - 1 = 9999
** 	ce masque permet ensuite de récuperer les n bits de la partie fractionnaire
**	une fois qu'on a les bits représentant la partie fractionnaire on les divise
**  2^n afin que la virgule soit placé au bon endroit
**  
*/
float Fixed::toFloat( void ) const{
	uint32_t fractionBits = this->value & ((1 << this->nb_bits) - 1);
	uint32_t intBits = this->value >> this->nb_bits;
	float fractionValue = static_cast<float>(fractionBits) / (1 << this->nb_bits);
	return (float)this->value / (float)(1 << Fixed::nb_bits);
}

int Fixed::toInt( void ) const{
	uint32_t intBits = this->value >> this->nb_bits;
	return(static_cast<int>(intBits));
}

/*

	operators

*/

Fixed& Fixed::operator=(const Fixed& from) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &from)
        this->value = from.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}