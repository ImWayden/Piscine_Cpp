/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:40:51 by wayden            #+#    #+#             */
/*   Updated: 2024/01/26 12:47:36 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "Includes.hpp"


class Fixed{
public:
	Fixed( void );
	Fixed(const Fixed& autre);
	Fixed(const int raw);
	Fixed(const float raw);
	~Fixed( void );

	int		getRawBits() const;
    void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	
	bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

	Fixed& operator=(const Fixed& autre);
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int); 
private:
	int value;
	static const int nb_bits = 8;
	
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
