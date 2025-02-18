/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 23:53:40 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 23:53:52 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "headers/includes.hpp"  // Inclure le fichier où la classe Array est définie

int main() {
    // Test du constructeur sans paramètre
    Array<int> arr1;
    std::cout << "Size of arr1: " << arr1.size() << std::endl;

    // Test du constructeur avec un nombre d'éléments
    Array<int> arr2(5);
    std::cout << "Size of arr2: " << arr2.size() << std::endl;

    // Test du constructeur de copie
    Array<int> arr3 = arr2;
    std::cout << "Size of arr3 (copy of arr2): " << arr3.size() << std::endl;

    // Test de l'opérateur []
    for (size_t i = 0; i < arr2.size(); ++i) {
        arr2[i] = i * 10;  // Initialisation des éléments
    }

    std::cout << "arr2 after modification:" << std::endl;
    for (size_t i = 0; i < arr2.size(); ++i) {
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    }

    // Test de l'opérateur d'assignation
    arr1 = arr2;
    std::cout << "arr1 after assignment from arr2:" << std::endl;
    for (size_t i = 0; i < arr1.size(); ++i) {
        std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;
    }

    // Test de l'accès hors limites
    try {
        std::cout << "Accessing arr2[10]: " << arr2[10] << std::endl;  // Hors limites
    }
    catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}