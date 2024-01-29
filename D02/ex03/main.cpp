/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:39:08 by wayden            #+#    #+#             */
/*   Updated: 2024/01/26 18:12:58 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

int main() {
    Point a(0, 0);
    Point b(1, 0);
    Point c(0, 1);
    Point testPoint(0.0033f, 0.089f);

    bool insideTriangle = bsp(a, b, c, testPoint);

    std::cout << "Is the point inside the triangle? " << (insideTriangle ? "Yes" : "No") << std::endl;

    return 0;
}