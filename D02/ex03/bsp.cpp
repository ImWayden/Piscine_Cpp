/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:56:10 by wayden            #+#    #+#             */
/*   Updated: 2024/01/26 18:13:19 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

/*
**	• a, b, c : Les sommets de notre cher triangle.
**	• point : Le point à évaluer.
**	• Retourne : True si le point est à l’intérieur du triangle. False dans le cas contraire.
**	Cela veut dire que, si le point est un sommet ou placé sur une arrête, la fonction
**	retournera False.
*/
// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
// 	Point vect_AB = b - a;
// 	Point vect_BC = c - b;
// 	Point vect_AP = point - a;
// 	Point vect_BP = point - b;
// 	Fixed cross_product1 = vect_AB.getX() * vect_AP.getY() - vect_AB.getY() * vect_AP.getX();
// 	Fixed cross_product2 = vect_BC.getX() * vect_BP.getY() - vect_BC.getY() * vect_BP.getX();
	
// 	return(cross_product1 * cross_product2 > 0);
// }
/*
** barycentre
** calculer l'air du triangle englobant puis l'aire des 3 triangle formé grace au nouveau point
** additioner les 3 aires si elles sont égale a l'air de abc alors P fait partie de ABC
*/
Fixed abs(Fixed x)
{
	if (x < 0)
		return x * -1;
	return x;
}

Fixed Area(Point const p1, Point const p2, Point const p3)
{
	Fixed a = p1.getX() * (p2.getY() - p3.getY());
	Fixed b = p2.getX() * (p3.getY() - p1.getY());
	Fixed c = p3.getX() * (p1.getY() - p2.getY());
	return (abs((a + b + c)/2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	return ((Area(a, b, c)) == (Area(point, b, c) + Area(point, c, a) + Area(point, a, b)));
}
/*
Calculez les vecteurs AB, BC, et AP.
AB=B−A
BC=C−B
AP=P−A

Calculez les produits vectoriels 
AB×AP et BC×BP.
cross_product_1=AB.x×AP.y−AB.y×AP.x
cross_product_2=BC.x×BP.y−BC.y×BP.x

Si les produits vectoriels ont des signes opposés, alors le point P est à l'intérieur du triangle.
isInside=(cross_product_1×cross_product_2)<0
*/