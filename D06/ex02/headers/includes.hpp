/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:04:21 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 07:06:00 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

typedef unsigned long int	uintptr_t;

# include <string>
# include <cstring>
# include <limits>
# include <ctime>
# include <cstdlib>
# include <iostream>
# include <iomanip>

# include "Class.hpp" 

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif