/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:25:00 by wayden            #+#    #+#             */
/*   Updated: 2025/02/16 23:28:19 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "includes.hpp"


template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end()) {
        throw std::runtime_error("Valeur non trouvée dans le conteneur");
    }
    
    return it;
}


#endif