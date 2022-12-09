/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:19:47 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/09 00:09:58 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief Espera a que terminen los forks lanzados 
 * 
 * @param data Estructura de datos
 */
static void	wait_process(t_data *data)
{
	int	status;
	int	i;

	i = 0;
	while (i < data->params.n_philo)
	{
		waitpid(data->id_forks[i], &status, 0);
		i++;
	}
}

static void	init_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->params.n_philo)
	{
		sem_post(data->sems.sem_start);
		i++;
	}
}

/**
 * @brief Obtiene la informacion inicial del filosofo
 * 
 * @param i posicion del filosofo
 * @return t_philo estructura del filosofo
 */
t_philo	start_philo(int i)
{
	t_philo	philo;

	philo.id = i + 1;
	philo.is_alive = true;
	philo.last_food = get_timestamp();
	philo.last_sleep = 0;
	philo.n_eat = 0;
	philo.status = THINK;
	return (philo);
}

/**
 * @brief Crea los procesos de los filosofos
 * fork = 0 para el proceso hijo
 * @param data Estructura de datos
 */
void	create_process(t_data *data)
{
	int		i;
	pid_t	pid;

	data->id_forks = malloc(sizeof(pid_t) * data->params.n_philo);
	if (data->id_forks == NULL)
		return ;
	start_threads(data);
	i = 0;
	while (i < data->params.n_philo)
	{
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
			process_start(data, i);
		data->id_forks[i] = pid;
		i++;
	}
	init_process(data);
	wait_process(data);
}
