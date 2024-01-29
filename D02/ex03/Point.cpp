/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:56:44 by wayden            #+#    #+#             */
/*   Updated: 2024/01/26 17:37:06 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

Point::Point( void ) : x(0), y(0) {}

Point::Point(float _x, float _y) : x(_x), y(_y) {}

Point::Point(const Point& from): x(from.x), y(from.y){}

Point::~Point( void ) {}

Fixed Point::getX( void ) const{
	return(this->x);
}

Fixed Point::getY( void ) const{
	return(this->y);
}

Point& Point::operator=(Point& autre){
    ((Fixed)(this->x)).setRawBits(autre.getX().getRawBits());
    ((Fixed)(this->y)).setRawBits(autre.getY().getRawBits());
    return *this;
}

Point Point::operator-(const Point& autre) const {
    return Point((this->x - autre.x).toFloat(), (this->y - autre.y).toFloat());
}

