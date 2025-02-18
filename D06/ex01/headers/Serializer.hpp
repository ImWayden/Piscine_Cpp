/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 05:38:27 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 06:25:52 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "includes.hpp"

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data *deserialize(uintptr_t raw);
private:
	Serializer();
	~Serializer();
	Serializer &operator=(const Serializer &);
};



#endif