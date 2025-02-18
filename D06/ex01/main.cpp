/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 06:18:48 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 06:31:36 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;


	Data test = Data(11, 'a');

	std::cout << "test" << std::endl;
	std::cout << "lvl : " << test.lvl << std::endl;
	std::cout << "id : " << test.id << std::endl;

	uintptr_t serialized = Serializer::serialize(&test);
	Data* deserialized = Serializer::deserialize(serialized);
	
	std::cout << "\ndeserialized" << std::endl;	
	std::cout << "lvl : " << deserialized->lvl << std::endl;
	std::cout << "id : " << deserialized->id << std::endl;

}