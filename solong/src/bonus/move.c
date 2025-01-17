/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:08:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 13:08:53 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	can_move(t_vars *vars, char dir)
{
	char	next_pos;

	if (dir == 'U')
		next_pos = vars->map[vars->character.y - 1][vars->character.x];
	if (dir == 'D')
		next_pos = vars->map[vars->character.y + 1][vars->character.x];
	if (dir == 'L')
		next_pos = vars->map[vars->character.y][vars->character.x - 1];
	if (dir == 'R')
		next_pos = vars->map[vars->character.y][vars->character.x + 1];
	if (next_pos == '1')
		return (0);
	if (next_pos == 'E' && vars->collect > 0)
		return (0);
	return (1);
}

char	get_direction(int keycode)
{
	if (keycode == 13 || keycode == 126)
		return ('U');
	if (keycode == 1 || keycode == 125)
		return ('D');
	if (keycode == 0 || keycode == 123)
		return ('L');
	if (keycode == 2 || keycode == 124)
		return ('R');
	return (' ');
}

void	move_char(t_vars *vars, char dir)
{
	t_coord	coords;

	vars->map[vars->character.y][vars->character.x] = '0';
	coords.x = vars->character.x;
	coords.y = vars->character.y;
	if (dir == 'U')
		coords.y = --vars->character.y;
	if (dir == 'D')
		coords.y = ++vars->character.y;
	if (dir == 'L')
		coords.x = --vars->character.x;
	if (dir == 'R')
		coords.x = ++vars->character.x;
		vars->character.x++;
	if (vars->map[coords.y][coords.x] == 'E' && vars->collect == 0)
		exit(0);
	if (vars->map[coords.y][coords.x] == 'O')
		exit(0);
	vars->map[coords.y][coords.x] = 'P';
}
