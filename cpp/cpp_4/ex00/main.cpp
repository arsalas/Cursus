/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:30:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/23 16:17:50 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animal = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	delete dog;
	delete cat;
	delete animal;

	std::cout << "-----Wrong animal-----" << std::endl;
	WrongAnimal *wAnimal = new WrongAnimal();
	WrongAnimal *wCat = new WrongCat();

	std::cout << wCat->getType() << std::endl;
	wCat->makeSound();
	wAnimal->makeSound();
	delete wCat;
	delete wAnimal;
	{
		std::cout << "-----Copy-----" << std::endl;
		Cat cat = Cat();
		Cat copy = Cat(cat);
		cat.makeSound();
		copy.makeSound();
	}

	return 0;
}