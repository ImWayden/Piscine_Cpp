/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:02:43 by wayden            #+#    #+#             */
/*   Updated: 2025/06/28 23:36:28 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

void printVector(const std::vector<int>& vec) {
	std::cout << "Vector contents: ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printDeque(const std::deque<int>& deq) {
	std::cout << "Deque contents: ";
	for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printVector2(const std::vector<int>& i, const std::vector<int>& vec) {
	std::cout << "Vector contents: ";
	for (std::vector<int>::const_iterator it = i.begin(); it != i.end(); ++it) {
		std::cout << vec[*it] << " ";
	}
	std::cout << std::endl;
}

void test(std::vector<int> v_ints)
{
	clock_t start_std_sort = clock();
	std::sort(v_ints.begin(), v_ints.end());
	clock_t end_std_sort = clock();
	
	double time_std_sort_ms = static_cast<double>(end_std_sort - start_std_sort) / CLOCKS_PER_SEC * 1000.0;
	
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << v_ints.size()
	          << " elements with std::sort (std::vector) : " << time_std_sort_ms << " ms" << std::endl;
}

//test(v_ints);