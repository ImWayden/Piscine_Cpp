/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert2.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:11:10 by wayden            #+#    #+#             */
/*   Updated: 2025/06/27 12:19:25 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERT2_HPP
# define MERGEINSERT2_HPP

#include "includes.hpp"

extern int g_count;

template <typename Container>
Container merge_sort(Container& vec);


template <typename Container>
Container generate_jacob(int index)
{
	Container jacob;
	int a = 1;
	int b = 1;

	while (b < index) {
		jacob.push_back(b);
		int next = b + 2 * a;
		a = b;
		b = next;
	}
	if (b == index) {
		jacob.push_back(b);
	} else if (jacob.empty() || jacob.back() != index) {
		jacob.push_back(index);
	}

	return jacob;
}

template <typename Container>
Container permute(const Container& permutation, const Container& vec, const Container& vec2)
{
	Container res;
	for(size_t i = 0; i < permutation.size(); i++)
		res.push_back(vec[permutation[i]]);
	return res;
}

template <typename Container>
int binary_insert(const Container& vec, Container& index_main, int index_value, int value, size_t limit)
{
	size_t left = 0;
	size_t right = limit;
	while (left < right)
	{
		size_t mid = (left + right) / 2;
		g_count++;
		if (value < vec[index_main[mid]])
			right = mid;
		else
			left = mid + 1;
	}
	index_main.insert(index_main.begin() + left, index_value);
	return left;
}

template <typename Container>
Container insert_sort(const Container& index_pend, Container& index_main, const Container& vec)
{
	Container jacob = generate_jacob<Container>(index_pend.size());
	size_t offset = 0;
	size_t nb_insert = 0;
	size_t limit = 0;

	index_main.insert(index_main.begin(), index_pend[0]);
	nb_insert++;
	for(size_t i = 1; i < jacob.size(); i++)
	{
		offset = 0;
		for(int j = jacob[i] - 1; j > jacob[i-1] - 1; j--)
		{
			limit = calc_limit(j, nb_insert, offset);
			offset += (limit == binary_insert<Container>(vec, index_main, index_pend[j], vec[index_pend[j]], limit));
			nb_insert++;
		}
	}
	return index_main;
}

template <typename Container>
void make_idx_pend(Container& pend_idx, const Container& main_idx, const Container& vec)
{
	for(size_t i = 0; i < main_idx.size(); i++)
		pend_idx.push_back(main_idx[i] - 1);
	if(vec.size() % 2)
		pend_idx.push_back(vec.size() - 1);
}

template <typename Container>
void make_idx_main(Container& main_idx, const Container& vec)
{
	Container main;
	for(size_t i = 1; i < vec.size(); i += 4)
	{
		if(i+2 < vec.size())
		{
			g_count++;
			if(vec[i] > vec[i+2])
			{
				main.push_back(vec[i+2]);
				main_idx.push_back(i+2);
				main.push_back(vec[i]);
				main_idx.push_back(i);
			}
			else
			{
				main.push_back(vec[i]);
				main_idx.push_back(i);
				main.push_back(vec[i+2]);
				main_idx.push_back(i+2);
			}
		}
		else
		{
			main.push_back(vec[i]);
			main_idx.push_back(i);
			break;
		}
	}
	if(main.size() > 1)
	{
		Container permu = merge_sort<Container>(main);
		main_idx = permute<Container>(permu, main_idx, vec);
	}
}

template <typename Container>
Container merge_sort(Container& vec)
{
	Container pend_idx;
	Container main_idx;

	make_idx_main<Container>(main_idx, vec);
	make_idx_pend<Container>(pend_idx, main_idx, vec);
	Container permu = insert_sort<Container>(pend_idx, main_idx, vec);
	return permu;
}

template <typename Container>
void merge_insert(Container& vec)
{
	Container permu;
	for(size_t i = 0; i+1 < vec.size(); i += 2)
	{
		g_count++;
		if(vec[i] > vec[i+1])
		{
			int swap = vec[i];
			vec[i] = vec[i+1];
			vec[i+1] = swap;
		}
	}
	permu = merge_sort<Container>(vec);
	vec = permute<Container>(permu, vec, vec);
	std::cout << "count : " << g_count << std::endl; 
}

template <typename Container>
void printContent(std::string str,Container& v_ints)
{
	std::cout << str;
	for(size_t i = 0; i < v_ints.size(); i++)
		std::cout << " " << v_ints[i];
	std::cout << std::endl;
}

#endif //MERGEINSERT2_HPP