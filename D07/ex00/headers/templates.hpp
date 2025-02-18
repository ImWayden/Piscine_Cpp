/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:50:10 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 22:10:10 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP



# include "includes.hpp"

//wanted to do a XOR swap but it's n ot compatible with every type of var so meh..
template<typename T>
void swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T min(const T& a, const T&b) {return (a < b) ? a : b;}

template<typename T>
T max(const T& a, const T&b) {return (a > b) ? a : b;}

#endif