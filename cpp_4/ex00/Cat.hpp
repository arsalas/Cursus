/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 15:27:40 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_H
#define Cat_H
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{

public:
	Cat(void);
	~Cat(void);
	void makeSound(void);
};

#endif