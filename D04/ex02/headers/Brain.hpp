/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:56:50 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 16:55:06 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include "Includes.hpp"

class Brain {
public:
    Brain( void );
    Brain(const Brain& from);
    ~Brain( void );

    Brain& operator=(const Brain& from);
private:
    std::string ideas[100];
};

#endif
