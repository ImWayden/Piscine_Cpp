/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:05:42 by wayden            #+#    #+#             */
/*   Updated: 2025/06/28 18:37:57 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_HPP
# define PROTO_HPP

# include "includes.hpp"
# include "PmergeMe.hpp"

void printVector(const std::vector<int>& v);
void printDeque(const std::deque<int>& d);
void printVector2(const std::vector<int>& i, const std::vector<int>& vec);

size_t calc_limit(size_t j, size_t nb_insert, size_t offset);
void merge_insert(std::vector<int>& vec, size_t pair_level);

extern int g_count;

#endif