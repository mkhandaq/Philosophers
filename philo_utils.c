/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:55:35 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/05/26 13:56:49 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    get_time()
{
	struct timeval  tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_philo *philo, char *msg)
{
	long	current_time;

	pthread_mutex_lock(&philo->data->print_mutex);
	current_time = get_time() - philo->data->start_time;
	printf("%ld %d %s\n", current_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	is_dead(t_data *data)
{
	int	dead_check;

	dead_check = 0;
	pthread_mutex_lock(&data->death_mutex);
	if (data->someone_died == 1)
		dead_check = 1;
	pthread_mutex_unlock(&data->death_mutex);
	return dead_check;
}

int	death_check(t_data *data)
{
	int	i;
	long	time_check;

	i = 0;
	while(i < data->num_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		time_check = get_time() - data->philos[i].last_meal_time;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		if(time_check > data->time_to_die)
		{
			print_status(&data->philos[i], "died");
			pthread_mutex_lock(&data->death_mutex);
			data->someone_died = 1;
			pthread_mutex_unlock(&data->death_mutex);
			return 1;
		}
		i++;
	}
	return 0;
}

int	did_eat_all(t_data *data)
{
	int	i;
	int	meals_ate;

	if(data->must_eat_count == -1)
		return 0;
	i = 0;
	while(i < data->num_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		meals_ate = data->philos[i].meals_eaten;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		if (meals_ate < data->must_eat_count)
			return 0;
		i++;
	}
	pthread_mutex_lock(&data->death_mutex);
	data->someone_died = 1;
	pthread_mutex_unlock(&data->death_mutex);
	return 1;
}
