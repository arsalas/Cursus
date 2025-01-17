/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:58 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 10:43:26 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief Comprueba si el el valor pasado es un digito
 * 
 * @param c character
 * @return int 1 si es digito 0 si no lo es
 */
static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * @brief Comprueba si el caracter pasado es un delimitador de la funcion atoi
 * 
 * @param d character
 * @return int 1 si lo es 0 si no lo es
 */
static int	is_atoi_delimiter(unsigned char d)
{
	if (d == ' ' || d == '\t' || d == '\n'
		|| d == '\f' || d == '\r' || d == '\v')
		return (1);
	else
		return (0);
}

/**
 * @brief Transforma un string en un int
 * 
 * @param str numero en string
 * @return int numero en int
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	while (is_atoi_delimiter(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

/**
 * @brief Imprime por pantalla el log de la accion
 * 
 * @param data estructura de datos del programa
 * @param philo id del filosofo
 * @param action accion a imprimir
 */
void	print_log(t_data *data, int philo, char	*desc)
{
	printf(UGRN "%lli" RESET BHWHT"\t%i\t" RESET "%s\n",
		get_timestamp() - data->timestamp, philo, desc);
}
