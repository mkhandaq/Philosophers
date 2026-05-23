/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:55:57 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/05/23 03:08:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc (sizeof(pthread_mutex_t) * data->num_philos);
	if(!data->forks)
		return 0;
	i = 0;
	while(i < data->num_philos)
	{
		if(pthread_mutex_init(&data->forks[i], NULL))
		{
			while(i--)
				pthread_mutex_destroy(&data->forks[i]);
			return 0;
		}
		i++;
	}
	return 1;
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if(!data->philos)
		return 0;
	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal_time = 0;
		data->philos[i].meals_eaten = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].data = data;
		if(pthread_mutex_init(&data->philos[i].meal_mutex, NULL))
			return 0;
		i++;
	}
	return 1;
}

int	init_data(t_data *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL) || 
	pthread_mutex_init (&data->death_mutex, NULL) ||
	!init_forks(data) || !init_philos(data))
		return 0;
	return 1;
}

void	nuke(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
	if (data->philos)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->philos[i].meal_mutex);
			i++;
		}
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	free(data->forks);
	free(data->philos);
}
