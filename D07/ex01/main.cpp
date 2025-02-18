/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:23:36 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 22:29:50 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t arr_length = sizeof(arr) / sizeof(arr[0]);
    
    iter(arr, arr_length, print_element<int>);
    std::cout << std::endl;

    double arr_doubles[] = {1.1, 2.2, 3.3, 4.4};
    size_t arr_doubles_length = sizeof(arr_doubles) / sizeof(arr_doubles[0]);
    
    iter(arr_doubles, arr_doubles_length, print_element<double>);
    std::cout << std::endl;

	char arr_char[] = {'a', 'b', 'c', 'd', 'e'};
    size_t arr_char_length = sizeof(arr_char) / sizeof(arr_char[0]);
    
    iter(arr_char, arr_char_length, print_element<char>);
    std::cout << std::endl;
    return 0;
}