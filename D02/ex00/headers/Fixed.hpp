/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:40:51 by wayden            #+#    #+#             */
/*   Updated: 2024/01/25 14:12:58 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "Includes.hpp"


class Fixed{
public:
	Fixed( void );
	Fixed(const Fixed& autre);
	Fixed& operator=(const Fixed& autre);
	~Fixed( void );
	int getRawBits() const;
    void setRawBits(int const raw);
private:
	int value;
	static const int nb_bits = 8;
	
};


#endif
