/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:33:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/29 16:18:19 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * Comprueba si ha terminado la partida
*/
static bool	is_game_over(t_data *data)
{
	int	i;
	int	eats;

	i = 0;
	eats = 0;
	while (i < data->params.n_philo)
	{
		if (data->philos[i].is_alive == false && data->philos[i].thread)
			return (true);
		if (data->philos[i].n_eat >= data->params.time_eats)
			eats++;
		i++;
	}
	return (false);
	if (data->params.time_eats == -1)
		return (false);
	if (eats == data->params.n_philo)
		return (true);
	return (false);
}

/**
 * Inicia el proceso de vida de cada filosofo
 */
void *philo_life(void *d)
{
	t_info	*info;
	t_data	*data;
	int		i;

	info = (t_info *)d;
	i = info->i;
	data = info->data;
	while (!is_game_over(data))
	{
		if (get_timestamp() - data->philos[i].last_food > data->params.t_die
		&& data->philos[i].status != EAT)
			philo_die(data, i);
		else if (data->philos[i].status == THINK
			&& can_take_fork(data, i))
			start_eat(data, i);
		else if (data->philos[i].status == EAT)
		{
			if (get_timestamp() - data->philos[i].last_food > data->params.t_eat)
				finish_eat(data, i);

		}
		else if (data->philos[i].status == SLEEP)
		{
			if (get_timestamp() - data->philos[i].last_sleep > data->params.t_sleep)
				finish_sleep(data, i);

		}
		usleep(1);
	}
	pthread_detach(data->philos[i].thread);
	return (NULL);
}