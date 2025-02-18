/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:01:19 by wayden            #+#    #+#             */
/*   Updated: 2025/02/18 01:03:40 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"


Span::Span(unsigned int n) : _sizeMax(n), _shortestSpan(((long long)std::numeric_limits<int>::min() - (long long)1) * 2), _longestSpan(0) {}
Span::~Span(){}

void Span::addNumber(int toAdd) {
	if (set.size() >= _sizeMax) {
		throw std::exception();
	}
	std::multiset<int>::iterator it = set.insert(toAdd);
	std::multiset<int>::iterator prevIt = it;
	std::multiset<int>::iterator nextIt = it;
	if(it != --set.end())
		++nextIt;
	if(it != set.begin())
		--prevIt;
	if (set.size() <= 1) {
		return;
	}
	if(it != prevIt)
	{
		size_t span = static_cast<size_t>(std::abs((long long)*prevIt - toAdd));
		if (_shortestSpan > span) _shortestSpan = span;
	} 
	if(it != nextIt)
	{
		size_t span = static_cast<size_t>(std::abs((long long)*nextIt - toAdd));
		if (_shortestSpan > span) _shortestSpan = span;
	} 
	
}

size_t Span::shortestSpan()
{
	if(set.size() <= 1)
		throw std::exception();
	return _shortestSpan;
}

size_t Span::longestSpan()
{
	if (set.size() <= 1)
		throw std::exception();
	return static_cast<size_t>(std::abs((long long)*set.begin() - (long long)*--set.end()));
}


Span &Span::operator=(const Span& from) {
    if (this != &from) {
        _sizeMax = from._sizeMax;
        _shortestSpan = from._shortestSpan;
        _longestSpan = from._longestSpan;
        set = from.set;
    }
    return *this;
}