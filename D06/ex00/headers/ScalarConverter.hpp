/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:06:56 by wayden            #+#    #+#             */
/*   Updated: 2025/02/13 18:14:14 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include "includes.hpp"

class ScalarConverter
{
public:
	static void convert(std::string literal);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);

	
};


#endif