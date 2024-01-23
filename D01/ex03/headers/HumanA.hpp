/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:10:36 by wayden            #+#    #+#             */
/*   Updated: 2024/01/23 12:49:52 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Includes.hpp"

class HumanA {
public:
    HumanA(std::string humanName, Weapon& weapon);
    ~HumanA();

    void attack();
private:
    Weapon& weapon;
    std::string name;
};

#endif