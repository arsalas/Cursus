/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:35:33 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/09 19:19:41 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "actions.h"
#include "errors.h"
#include "get_next_line_bonus.h"
#include "libft.h"
#include "stack.h"

/**
 * @brief Funcion que compara si dos strings son iguales
 * 
 * @param str1 string 1
 * @param str2 string 2
 * @return int retorna 1 si son igulas y 0 si son distintas
 */
static int	str_cmp(char *str1, char *str2)
{
	int	len_1;
	int	len_2;
	int	i;

	len_1 = ft_strlen(str1);
	if (str1[len_1 - 1] == '\n')
		len_1--;
	len_2 = ft_strlen(str2);
	if (len_1 != len_2)
		return (0);
	i = 0;
	while (i < len_1)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Encuentra la accion que hay que ejecutar o 
 * imprime error si la accion no es correcta
 * 
 * @param str accion a ejecutar
 * @param stack_a stack a
 * @param stack_b stack b
 */
static void	actions(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (str_cmp(str, "sa") == 1)
		sa(stack_a, 0);
	else if (str_cmp(str, "sb") == 1)
		sb(stack_b, 0);
	else if (str_cmp(str, "ss") == 1)
		ss(stack_a, stack_b, 0);
	else if (str_cmp(str, "pa") == 1)
		pa(stack_a, stack_b, 0);
	else if (str_cmp(str, "pb") == 1)
		pb(stack_a, stack_b, 0);
	else if (str_cmp(str, "ra") == 1)
		ra(stack_a, 0);
	else if (str_cmp(str, "rb") == 1)
		rb(stack_b, 0);
	else if (str_cmp(str, "rr") == 1)
		rr(stack_a, stack_b, 0);
	else if (str_cmp(str, "rra") == 1)
		rra(stack_a, 0);
	else if (str_cmp(str, "rrb") == 1)
		rrb(stack_b, 0);
	else if (str_cmp(str, "rrr") == 1)
		rrr(stack_a, stack_b, 0);
	else
		print_error();
}

/**
 * @brief Lee las instrucciones y las aplica para comprobar
 * si el stack esta ordenado
 * @param stack_a 
 * @param stack_b 
 */
void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;

	str = "";
	while (str)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		actions(str, stack_a, stack_b);
		free(str);
	}
	if (is_stack_sort(stack_a) == 1 && stack_b->len == 0)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}
