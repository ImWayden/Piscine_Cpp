/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:10:58 by wayden            #+#    #+#             */
/*   Updated: 2025/02/17 07:05:58 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include "includes.hpp"


//addNumbers got quit the big vunerability, if you give it pointeurs that aren't iterators it will try to work with it, i have no fuckign clue on how to not let it do that
class Span
{
public:
	Span(unsigned int n = 0);
	Span(Span& from);
	~Span();
	
	void addNumber(int toAdd);
	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end) {
		for (; begin != end; ++begin) {addNumber(*begin);}
	}
	size_t shortestSpan();
	size_t longestSpan();

	Span &operator=(const Span& from);
private:
	unsigned int _sizeMax;
	size_t _shortestSpan;
	size_t _longestSpan;
	std::multiset<int>	set; 
};

#endif