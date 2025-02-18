/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:06:54 by wayden            #+#    #+#             */
/*   Updated: 2025/02/18 04:46:05 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Invalid Args: Usage: ./btc <filename>" << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange exchanger; // Passe le chemin du fichier en argument
        exchanger.exchange(argv[1]); // Effectuer l'échange
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}