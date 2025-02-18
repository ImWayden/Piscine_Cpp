/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 07:03:38 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 07:20:50 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

int main() {
	std::srand(std::time(NULL));
    for (int i = 0; i < 5; ++i) {
        std::cout << "Test #" << i+1 << std::endl;

        Base* obj = generate();
        identify(obj);
		identify(*obj);
		delete obj;

        obj = generate();
        identify(obj);
		identify(*obj);
        delete obj;

        std::cout << std::endl;
    }

    return 0;
}