/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:50:10 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 23:55:20 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "includes.hpp"


template <typename T>
class Array 
{
public:
	Array() : data(NULL), length(0) {}
	Array(const Array<T>& from) : length(from.length)
	{
		data = new T[length]();
		for(size_t i = 0; i < length; i++)
			data[i] = from.data[i];
	}
	Array(unsigned int n) : length(n)
	{
		data = new T[length]();
	}
	~Array(){delete[] data;}

	T& operator[](size_t index)
	{
		if (index >= length) throw std::out_of_range("Index out of bounds");
		return data[index];
	}
	Array<T> &operator=(const Array<T>& from)
	{
		if(this != &from)
		{
			delete[] data;
			length = from.length;
			data = new T[length]();
			for(size_t i = 0; i < length; i++)
				data[i] = from.data[i];
		}
		return *this;
	}
	size_t size() const{return length;}
private:
	T* data;
	size_t length;
};

#endif