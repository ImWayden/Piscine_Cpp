/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:44:00 by wayden            #+#    #+#             */
/*   Updated: 2025/02/14 01:04:42 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_HPP
# define DEFINES_HPP
#include "includes.hpp"
enum e_type{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NOP
};

# define NANNED 0b01
# define INF 0b010
# define OVERFLOWINT 0b0100
# define OVERFLOWCHAR 0b01000
# define NONDISPLAYABLE 0b010000
# define NOPPED 0b100000

typedef int (*Converters)(std::string, double*, char*, int*, float*);

#endif