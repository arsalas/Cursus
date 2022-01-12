/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:54:48 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/10 16:45:19 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_bzero(void *str, size_t n)
{
	char	*s;

	s = (char *)str;
	while (n > 0)
	{
		*s = '\0';
		s++;
		n--;
	}
	return (str);
}
