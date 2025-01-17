/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 21:32:17 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed
{
private:
	int _value;
	static const int _bits = 8;

public:
	Fixed(void);
	Fixed(Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif