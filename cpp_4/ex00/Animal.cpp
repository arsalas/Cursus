/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:25:06 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/20 19:41:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal construct" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destroy " << std::endl;
}

std::string Animal::getType(void)
{
	return (type);
}

void Animal::makeSound(void) const
{
	std::cout << " " << std::endl;
}