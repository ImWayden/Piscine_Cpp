/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert4.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:29:36 by wayden            #+#    #+#             */
/*   Updated: 2025/06/28 17:38:42 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

typedef std::vector<int>::iterator it_type;

bool comp(it_type lhs, it_type rhs)
{
    g_count++;
    return *lhs < *rhs;
}

typedef struct s_PairInfo {
	size_t pair_level;
	size_t start;
	size_t compare_to;
	size_t increment;

	s_PairInfo(size_t lvl)
		: pair_level(lvl),
		  start(lvl - 1),
		  compare_to(lvl),
		  increment(lvl * 2) {}
} t_PairInfo;

std::vector<size_t> generate_jacob(size_t index)
{
	std::vector<size_t> jacob;
	int a = 1;
	int b = 1;

	while (b < index) { 	// Jacobsthal sequence: J(n) = J(n-1) + 2*J(n-2)
		jacob.push_back(b);
		int next = b + 2 * a;
		a = b;
		b = next;
	}
	if (b == index){ 	// If b == index, add it; otherwise, add index explicitly
		jacob.push_back(b);
	} else if (jacob.empty() || jacob.back() != index) {
		jacob.push_back(index);
	}
	return jacob;
}

void swap_blocks_from_end(std::vector<int>::iterator a_end, std::vector<int>::iterator b_end, size_t block_size)
{
	for (size_t i = 0; i < block_size; ++i)
		std::swap(*(a_end - i), *(b_end - i));
}

void insert(std::vector<it_type>& pend, std::vector<it_type>& main)
{
	std::vector<size_t> jacob;
	size_t offset = 0;
	size_t nb_insert = 0;
	it_type *limit;
	jacob = generate_jacob(pend.size());
	main.insert(main.begin(), *pend.begin());
	nb_insert++;
	for(size_t i = 1; i < jacob.size(); i++)
	{
		offset = 0;
		for(int j = jacob[i] - 1; j > jacob[i-1] - 1; j--)
		{
    		std::vector<it_type>::iterator  limit = main.begin() + j + nb_insert - offset;
			std::vector<it_type>::iterator  pos = std::upper_bound(main.begin(), limit, *(pend.begin() + j), comp);
			offset += (limit == pos);
			main.insert(pos, *(pend.begin() + j));
			nb_insert++;
		}
	}
}

template <typename Container, typename Iterator>
void rebuild_container(Container<Iterator>& main, Container<int>& container, s_PairInfo info)
{
	Container<int> tmp;
	tmp.resize(container.size());

	for (size_t i = 0; i < main.size(); ++i)
	{
		it_type end = main[i];
		it_type start = end - (info.compare_to - 1); 
		tmp.insert(tmp.end(), start, main[i] + 1);
	}
	std::copy(tmp.begin(), tmp.end(), container.begin());
}

void merge_insert(std::vector<int>& vec, size_t pair_level)
{
	if (vec.size() < 2 || pair_level == 0)
		return;
		
	t_PairInfo info(pair_level);
	int swap_count = 0;

	std::vector<int>::iterator start = vec.begin() + info.start;
	std::vector<it_type> pend;
	std::vector<it_type> main;
	while (start + info.compare_to < vec.end())
	{
		std::vector<int>::iterator left_last  = start;
		std::vector<int>::iterator right_last = start + info.compare_to;
		g_count++;
		if (*left_last > *right_last)
			swap_blocks_from_end(left_last, right_last, pair_level);
		pend.push_back(left_last);
		main.push_back(right_last);
		start += info.increment;
	}
	if(start < vec.end())
		pend.push_back(start);
	if (main.size() > 1)
		merge_insert(vec, pair_level * 2);
	insert(pend, main);
	rebuild_container(main, vec, info);
}