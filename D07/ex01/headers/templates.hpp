/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:50:10 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 22:24:49 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include "includes.hpp"

//wanted to do a XOR swap but it's n ot compatible with every type of var so meh..
template<typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
	for(size_t i = 0; i < length; i++)
		func(array[i]);
}

//function required for tests
template <typename T>
void print_element(T& element) {
    std::cout << element << " ";
}

#endif