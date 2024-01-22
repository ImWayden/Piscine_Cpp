/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:54:48 by wayden            #+#    #+#             */
/*   Updated: 2024/01/22 17:01:43 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"


bool isnum(const std::string& str){
	for (char caractere : str) 
	{
        if (!std::isdigit(caractere))
            return false;
    }
    return true;
}

int main() {
    std::string userInput;
    PhoneBook instance;

    std::cout << "Bienvenue sur PhoneBook, un Annuaire tres simple" << std::endl;

    while (true) {
		std::cout << "Commande :";
        std::getline(std::cin, userInput);

        if (!userInput.empty()) {
            if (userInput == "EXIT")
                break;
            else if (userInput == "ADD")
                instance.get_contact();
            else if (userInput == "SEARCH")
                instance.search();
        }
		if(std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl;
		}

          // Utiliser la fonction pour vider le tampon
    }

    return 0;
}