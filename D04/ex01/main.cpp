/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 04:07:18 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 16:55:53 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

int main( void )
{
	// {
	// 	std::cout << "\n\n\n\n";
	// 	const Animal* meta = new Animal();
	// 	const Animal* j = new Dog();
	// 	const Animal* i = new Cat();
	// 	std::cout << j->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound(); //will output the cat sound!
	// 	j->makeSound();
	// 	meta->makeSound();
	// 	delete meta;
	// 	delete j;
	// 	delete i;	
	// }	
	// {	
	// 	std::cout << "\n\n\n\n";
	// 	Animal Default;
	// 	Animal Default_clone(Default);
	// 	Cat		Default_Cat;
	// 	Cat		Default_Cat_Clone(Default_Cat);
	// 	Dog		Default_Dog;
	// 	Dog		Default_Dog_Clone(Default_Dog);
	
	// 	Default.makeSound();
	// 	std::cout << Default.getType() << " " << std::endl;
	// 	Default_clone.makeSound();
	// 	std::cout << Default_clone.getType() << " " << std::endl;
	// 	Default_Cat.makeSound();
	// 	std::cout << Default_Cat.getType() << " " << std::endl;
	// 	Default_Cat_Clone.makeSound();
	// 	std::cout << Default_Cat_Clone.getType() << " " << std::endl;
	// 	Default_Dog.makeSound();
	// 	std::cout << Default_Dog.getType() << " " << std::endl;
	// 	Default_Dog_Clone.makeSound();
	// 	std::cout << Default_Dog_Clone.getType() << " " << std::endl;
	// }
	// {
	// 	std::cout << "\n\n\n\n";
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* i = new WrongCat();
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound(); //will output the cat sound!
	// 	meta->makeSound();
	// 	delete meta;
	// 	delete i;	
	// }
	// {
	// 	std::cout << "\n\n\n\n";
	// 	const Animal* j = new Dog();
	// 	const Animal* i = new Cat();
	// 	delete j;//should not create a leak
	// 	delete i;
	// 	return 0;
	// }
	{
		std::cout << "\n\n\n\n";
    	const int arraySize = 10;
    	Animal *animalArray[arraySize];
	
    	// Remplissage du tableau avec des chiens et des chats
    	for (int i = 0; i < arraySize; ++i) {
    	    if (i % 2 == 0) {
    	        animalArray[i] = new Dog();
    	    } else {
    	        animalArray[i] = new Cat();
    	    }
    	}
		std::cout << std::endl;
    	// Parcours du tableau pour delete chaque Animal
    	for (int i = 0; i < arraySize; ++i) {
    	    delete animalArray[i];
    	}
	
    	return 0;
	}
}