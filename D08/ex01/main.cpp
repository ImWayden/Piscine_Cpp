/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 05:15:37 by wayden            #+#    #+#             */
/*   Updated: 2025/02/17 06:57:55 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

int main() {
    // Test avec l'ajout classique de nombres
    std::cout << "Test avec 5 éléments..." << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Devrait afficher 2
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Devrait afficher 14
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test avec un vecteur et l'ajout via des itérateurs
    std::cout << "\nTest avec ajout via des itérateurs..." << std::endl;
    Span sp2(10);
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(8);
    nums.push_back(7);
    nums.push_back(2);
    sp2.addNumbers(nums.begin(), nums.end());

    try {
        std::cout << "Shortest Span (après ajout par itérateurs): " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span (après ajout par itérateurs): " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test d'ajout d'un trop grand nombre d'éléments
    std::cout << "\nTest avec trop d'éléments..." << std::endl;
    Span sp3(5);
    try {
        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3);
        sp3.addNumber(4);
        sp3.addNumber(5);
        sp3.addNumber(6); // Va lancer une exception car la capacité maximale est atteinte
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test avec une plage d'itérateurs plus grande
    std::cout << "\nTest avec ajout d'une grande plage d'éléments..." << std::endl;
    Span sp4(10000);
    std::vector<int> largeInput(10000);
    for (int i = 0; i < 10000; ++i) {
        largeInput[i] = i;
    }
    sp4.addNumbers(largeInput.begin(), largeInput.end());

    try {
        std::cout << "Shortest Span (plage de 10000 éléments): " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest Span (plage de 10000 éléments): " << sp4.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	Span sp5(2);
	sp5.addNumber(std::numeric_limits<int>::min());
	sp5.addNumber(std::numeric_limits<int>::max());

	try {
        std::cout << "Shortest Span (plage de 10000 éléments): " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest Span (plage de 10000 éléments): " << sp5.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	Span sp6(3);
	sp6.addNumber(std::numeric_limits<int>::min());
	sp6.addNumber(std::numeric_limits<int>::max());
	sp6.addNumber(0);

	try {
        std::cout << "Shortest Span (plage de 10000 éléments): " << sp6.shortestSpan() << std::endl;
        std::cout << "Longest Span (plage de 10000 éléments): " << sp6.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	Span sp7(3);
	sp7.addNumber(50);
	sp7.addNumber(50);
	sp7.addNumber(51);

	try {
        std::cout << "Shortest Span (plage de 10000 éléments): " << sp7.shortestSpan() << std::endl;
        std::cout << "Longest Span (plage de 10000 éléments): " << sp7.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	Span sp8(5);
	int arr[] = {1, 2, 3, 4, 5};
    int* start = &arr[0];  // Pointeur sur la première valeur
    int* end = &arr[5];    // Pointeur après la dernière valeur (arr + 5)

    // Appel avec les pointeurs
    sp8.addNumbers(start, end);
	try {
        std::cout << "Shortest Span (plage de 10000 éléments): " << sp8.shortestSpan() << std::endl;
        std::cout << "Longest Span (plage de 10000 éléments): " << sp8.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}