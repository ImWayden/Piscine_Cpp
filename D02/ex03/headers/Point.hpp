/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:48:46 by wayden            #+#    #+#             */
/*   Updated: 2024/01/26 17:18:59 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Includes.hpp"

class Point{
public:
	Point( void );
	Point(float x, float y);
	Point(const Point &from);
	~Point( void );
	Fixed getX( void ) const;
	Fixed getY( void ) const;
	Point&	operator=(Point& autre);
	Point	operator-(const Point& autre) const;
private:
	Fixed const	x;
	Fixed const	y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);



#endif