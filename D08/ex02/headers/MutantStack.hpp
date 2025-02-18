/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:07:55 by wayden            #+#    #+#             */
/*   Updated: 2025/02/18 00:58:55 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include "includes.hpp"

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    // Utilisation de typedef pour définir les alias de types d'itérateurs
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Fonctions pour récupérer les itérateurs
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};


#endif