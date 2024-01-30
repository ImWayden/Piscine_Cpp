/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Includes.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:13:45 by wayden            #+#    #+#             */
/*   Updated: 2024/01/29 17:29:16 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INCLUDES_H
# define INCLUDES_H
# include <string>
# include <cstring>
# include <limits>
# include <cstdlib>
# include <ctime>
# include <iostream>
# include <fstream>
# include <sstream>
# include <bitset>
# include <cmath>

# include "defines.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

template <typename T>
const T& clamp(const T& value, const T& lower, const T& upper) {
    return (value < lower) ? lower : ((upper < value) ? upper : value);
}

#endif