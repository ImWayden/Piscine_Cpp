/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 05:45:37 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 06:24:43 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Serializer.hpp"


uintptr_t Serializer::serialize(Data *ptr)
{
	return static_cast<uintptr_t>(ptr->id) << 32 | ptr->lvl;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	int lvl = static_cast<int>(raw & 0xFFFFFFFF);
	char id = static_cast<char>(raw >> 32 & 0xFF);
	return (new Data(lvl, id));
}
