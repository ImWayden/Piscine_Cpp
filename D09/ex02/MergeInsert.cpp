/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:11:58 by wayden            #+#    #+#             */
/*   Updated: 2025/06/26 22:52:38 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"
int g_count = 0;

std::vector<int> generate_jacob(int index)
{
	std::vector<int> jacob;
	int a = 1;
	int b = 1;

	// Jacobsthal sequence: J(n) = J(n-1) + 2*J(n-2)
	while (b < index) {
		jacob.push_back(b);
		int next = b + 2 * a;
		a = b;
		b = next;
	}

	// If b == index, add it; otherwise, add index explicitly
	if (b == index){
		jacob.push_back(b);
	} else if (jacob.empty() || jacob.back() != index) {
		jacob.push_back(index);
	}

	return jacob;
}

std::vector<int> permute(std::vector<int> permutation, std::vector<int> vec, std::vector<int> vec2)
{
	std::vector<int> res;
	//printVector2(vec, vec2);
	for(size_t i = 0; i < permutation.size(); i++)
		res.push_back(vec[permutation[i]]);
	//for(size_t i = permutation.size(); i < vec.size(); i++)
		//res.push_back(vec[i]);
	//printVector2(res, vec2);
	return res;
}

int binary_insert(std::vector<int>& vec, std::vector<int>& index_main, int index_value, int value, size_t limit)
{
    size_t left = 0;
    size_t right = limit;
    while (left < right)
    {
        size_t mid = (left + right) / 2;
		g_count++;
        if (value < vec[index_main[mid]]) //comparing 
            right = mid;
        else
            left = mid + 1;
    }
    index_main.insert(index_main.begin() + left, index_value);
    return left;
}

size_t calc_limit(size_t j, size_t nb_insert, size_t offset)
{
	return (j + nb_insert - offset);	
}

std::vector<int> insert_sort(std::vector<int> index_pend, std::vector<int>& index_main, std::vector<int>& vec)
{
	std::vector<int> jacob;
	size_t offset = 0;
	size_t nb_insert = 0;
	size_t limit = 0;
	jacob = generate_jacob(index_pend.size());
	index_main.insert(index_main.begin(), index_pend[0]);
	nb_insert++;
	for(size_t i = 1; i < jacob.size(); i++)
	{
		offset = 0;
		//printVector2(index_main, vec);
		for(int j = jacob[i] - 1; j > jacob[i-1] - 1; j--)
		{
			limit = calc_limit(j, nb_insert, offset);
			offset += (limit == binary_insert(vec, index_main, index_pend[j], vec[index_pend[j]], limit));			
			nb_insert++;
		}
	}
	//for(int i = index_pend.size() - 1; i > jacob.back(); i--)
		//offset += (i - 1 == binary_insert(vec, index_main, index_pend[i], vec[index_pend[i]], calc_limit(i - 1, nb_insert, offset)));
	return index_main;
}

//this is avoidable if you really want toreduce comparaison operation on the implementation part too
void make_idx_pend(std::vector<int>& pend_idx, std::vector<int>& main_idx, std::vector<int>& vec)
{
	for(size_t i = 0; i < main_idx.size(); i++)
		pend_idx.push_back(main_idx[i] - 1);
	if(vec.size() % 2)
		pend_idx.push_back(vec.size() - 1);
	//printVector(pend_idx);
}

void make_idx_main(std::vector<int>& main_idx, std::vector<int>& vec)
{
	std::vector<int> main;
	for(size_t i = 1; i < vec.size(); i += 4)
	{
		if(i+2 < vec.size())
		{
			g_count++;
			if(vec[i] > vec[i+2]) //comparing
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
	//printVector(main_idx);
	//printVector2(main_idx, vec);
	//printVector(main);
	if(main.size() > 1)
	{
		std::vector<int> permu = merge_sort(main);
		//printVector(permu);
		main_idx = permute(permu, main_idx, vec);
	}

	//printVector(main_idx);
	//printVector2(main_idx, vec);
}

//pend.size() = vec.size() - main.size()
//insert = pend.size() + (vec.size() % 2) 
//recoit un vec dont les paires sont trie
std::vector<int> merge_sort(std::vector<int>& vec)
{
	std::vector<int> pend_idx;
	std::vector<int> main_idx;

	//printVector(vec);
	make_idx_main(main_idx, vec);
	make_idx_pend(pend_idx, main_idx, vec);
	std::vector<int> permu = insert_sort(pend_idx, main_idx, vec);
	//std::cout << "permu : ";
	//printVector(permu);
	return permu;
}

void merge_insert(std::vector<int> &vec)
{
	std::vector<int> permu;
	for(size_t i = 0; i+1 < vec.size(); i += 2)
	{
		g_count++;
		if(vec[i] > vec[i+1])// comparing
		{
			int swap = vec[i];
			vec[i] = vec[i+1];
			vec[i+1] = swap;
		}
	}
	permu = merge_sort(vec);
	vec = permute(permu, vec, vec);
	std::cout << "count : " << g_count << std::endl; 
}



// std::vector<int> insert_sort(std::vector<int> index_pend, std::vector<int>& index_main, std::vector<int>& vec)
// {
// 	std::vector<int> jacob;
// 	size_t offset = 0;
// 	size_t nb_insert = 0;
// 	jacob = generate_jacob(index_pend.size());
// 	index_main.insert(index_main.begin(), *index_pend.begin());
// 	for(int i = 1; i < jacob.size(); i++)
// 		for(int j = jacob[i]; j > jacob[i-1]; j--)
// 			binary_insert(vec, index_main, index_pend[j], vec[index_pend[j]], );
// 	for(int i = index_pend.size(); i > jacob.back(); i--)
// 		binary_insert(vec, index_main, index_pend[i], vec[index_pend[i]]);	
// }

// //renvois index trie
// std::vector<int> merge_sort(std::vector<int>& vec)
// {
// 	std::vector<int> res;
// 	std::vector<int> main;
// 	std::vector<int> permu;
// 	std::vector<int> index_pend;
// 	std::vector<int> index_main;
// 	for(int i = 0; i+1 <= vec.size(); i += 2)
// 	{
		
// 		if(vec[i] > vec[i+1])
// 		{
// 			main.push_back(vec[i]);
// 			index_main.push_back(i);
// 			index_pend.push_back(i+1);
// 		}
// 		else
// 		{
// 			main.push_back(vec[i+1]);
// 			index_main.push_back(i+1);
// 			index_pend.push_back(i);
// 		}
// 	}
// 	if(main.size() > 1)
// 	{
// 		permu = merge_sort(main);
// 		index_main = permute(permu, index_main);
// 		index_pend = permute(permu, index_pend);
// 	}
// 	return insert_sort(index_pend, index_main, vec);	
// }
