/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:19:57 by wayden            #+#    #+#             */
/*   Updated: 2025/06/28 23:39:49 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <cstddef>

template<template<typename, typename> class ContainerT>
class PmergeMe
{
public:
	typedef ContainerT<int, std::allocator<int> > container_type;
	typedef typename container_type::iterator iterator;
	typedef ContainerT<iterator, std::allocator<iterator> > iterator_container;

private:
	static size_t g_count;

public:
	PmergeMe() {}
	PmergeMe(const PmergeMe&) {}
	PmergeMe& operator=(const PmergeMe&) { return *this; }
	~PmergeMe() {}

	static void merge_insert(container_type& cont, size_t pair_level);
	static size_t get_reset_compare_count();

private:
	static bool comp(iterator lhs, iterator rhs);
	static container_type generate_jacob(int index);
	static void swap_blocks_from_end(iterator a_end, iterator b_end, size_t block_size);
	static void insert(iterator_container& pend, iterator_container& main);
	static void rebuild_container(iterator_container& main, container_type& container, size_t pair_size);
};

template<template<typename, typename> class ContainerT>
size_t PmergeMe<ContainerT>::g_count = 0;


template<template<typename, typename> class ContainerT>
size_t PmergeMe<ContainerT>::get_reset_compare_count()
{
    size_t temp = g_count;
    g_count = 0;
    return temp;
}

template<template<typename, typename> class ContainerT>
bool PmergeMe<ContainerT>::comp(iterator lhs, iterator rhs)
{
	g_count++;
	return *lhs < *rhs;
}

template<template<typename, typename> class ContainerT>
typename PmergeMe<ContainerT>::container_type PmergeMe<ContainerT>::generate_jacob(int index)
{
	container_type jacob;
	int a = 1, b = 1;

	while (b < index)
	{
		jacob.push_back(b);
		int next = b + 2 * a;
		a = b;
		b = next;
	}
	if (b == index)
		jacob.push_back(b);
	else
		jacob.push_back(index);
	return jacob;
}

template<template<typename, typename> class ContainerT>
void PmergeMe<ContainerT>::swap_blocks_from_end(iterator a_end, iterator b_end, size_t block_size)
{
	for (size_t i = 0; i < block_size; ++i)
		std::swap(*(a_end - i), *(b_end - i));
}

/*
    Short explanation on why "typename" is required before iterator_container::iterator:
    The compiler doesn't know that iterator_container is a container, it only sees a dependent type.
    Therefore, it cannot assume that "iterator" is a type and not a static member or function.
    To remove this ambiguity, we must explicitly tell the compiler that "iterator" is a type using the "typename" keyword.
*/
template<template<typename, typename> class ContainerT>
void PmergeMe<ContainerT>::insert(iterator_container& pend, iterator_container& main)
{
	container_type jacob = generate_jacob(pend.size());
	size_t offset = 0;
	size_t nb_insert = 0;

	main.insert(main.begin(), pend[0]);
	nb_insert++;

	for (size_t i = 1; i < jacob.size(); ++i)
	{
		offset = 0;
		int j_start = jacob[i] - 1;
		int j_end = jacob[i - 1] - 1;
		for (int j = j_start; j > j_end; --j)
		{
			typename iterator_container::iterator limit = main.begin() + j + nb_insert - offset;
			typename iterator_container::iterator pos = std::upper_bound(main.begin(), limit, pend[j], comp);
			if (limit == pos)
				offset++;
			main.insert(pos, pend[j]);
			nb_insert++;
		}
	}
}

template<template<typename, typename> class ContainerT>
void PmergeMe<ContainerT>::rebuild_container(iterator_container& main, container_type& container, size_t pair_size)
{
	container_type tmp;

	for (size_t i = 0; i < main.size(); ++i)
	{
		iterator end = main[i];
		iterator start = end - (pair_size - 1);
		tmp.insert(tmp.end(), start, end + 1);
	}
	std::copy(tmp.begin(), tmp.end(), container.begin());
}

template<template<typename, typename> class ContainerT>
void PmergeMe<ContainerT>::merge_insert(container_type& cont, size_t pair_level)
{
	if (cont.size() < 2 || pair_level == 0)
		return;

	size_t start_index = pair_level - 1;
	size_t compare_to = pair_level;
	size_t increment = pair_level * 2;

	iterator start = cont.begin() + start_index;

	iterator_container pend;
	iterator_container main;

	while (start + compare_to < cont.end())
	{
		iterator left_last = start;
		iterator right_last = start + compare_to;

		g_count++;
		if (*left_last > *right_last)
			swap_blocks_from_end(left_last, right_last, pair_level);

		pend.push_back(left_last);
		main.push_back(right_last);
		start += increment;
	}
	if (start < cont.end())
		pend.push_back(start);

	if (main.size() > 1)
		merge_insert(cont, pair_level * 2);
	insert(pend, main);
	rebuild_container(main, cont, compare_to);
}

#endif // PMERGEME_HPP

