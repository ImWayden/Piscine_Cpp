/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:40:51 by wayden            #+#    #+#             */
/*   Updated: 2024/01/25 17:07:44 by wayden           ###   ########.fr       */
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
	
	Fixed& operator=(const Fixed& autre);
private:
	int value;
	static const int nb_bits = 8;
	
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
