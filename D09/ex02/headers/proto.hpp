/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:05:42 by wayden            #+#    #+#             */
/*   Updated: 2025/06/26 19:43:00 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_HPP
# define PROTO_HPP

# include "includes.hpp"
# include "PmergeMe.hpp"

void printVector(const std::vector<int>& v);
void printDeque(const std::deque<int>& d);
void printVector2(const std::vector<int>& i, const std::vector<int>& vec);

void merge_insert(std::vector<int> &vec);
std::vector<int> merge_sort(std::vector<int>& vec);
#endif