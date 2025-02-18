/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:06:26 by wayden            #+#    #+#             */
/*   Updated: 2025/02/13 21:12:06 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

int main(int argc, char **argv)
{
	(void) argc;
	ScalarConverter::convert(argv[1]);
	return 0;
}