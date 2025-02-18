/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:40:25 by wayden            #+#    #+#             */
/*   Updated: 2025/02/18 00:49:08 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

int main() {
    // Test avec MutantStack
    std::cout << "=== Test avec MutantStack ===\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Afficher les éléments avec l'itérateur
    std::cout << "Affichage de MutantStack (itérateurs):\n";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Taille et pop
    std::cout << "Taille après pop: " << mstack.size() << std::endl;
    mstack.pop();

    std::cout << "Taille après pop encore: " << mstack.size() << std::endl;
    
    // Test de reverse iterators
    std::cout << "Affichage de MutantStack en sens inverse:\n";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    // Comparaison avec std::list
    std::cout << "=== Test avec std::list ===\n";
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    // Afficher les éléments avec l'itérateur de list
    std::cout << "Affichage de std::list:\n";
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    // Comparaison avec std::vector
    std::cout << "=== Test avec std::vector ===\n";
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(17);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    vec.push_back(0);

    // Afficher les éléments avec l'itérateur de vector
    std::cout << "Affichage de std::vector:\n";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    // Comparaison avec std::stack (via MutantStack)
    std::cout << "=== Test avec std::stack (via MutantStack) ===\n";
    std::stack<int, std::deque<int> > stack;
    stack.push(5);
    stack.push(17);
    stack.push(3);
    stack.push(5);
    stack.push(737);
    stack.push(0);

    // Affichage de la stack (accès avec pop)
    std::cout << "Affichage de std::stack (via pop):\n";
    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    std::cout << std::endl;

    // Comparaison de l'affichage entre MutantStack, std::list et std::vector
    std::cout << "=== Comparaison de l'affichage ===\n";
    std::cout << "Affichage de MutantStack (itérateurs):\n";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "Affichage de std::list:\n";
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "Affichage de std::vector:\n";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}