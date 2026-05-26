/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:35:17 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/04/30 11:56:48 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void    usleep_but_better(long long ms)
{
	long long start;

	start = get_time();
	while((get_time() - start) < ms)
		usleep(100);
}

static void    eat(t_philo *philo)
{
	if (philo->data->num_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		usleep_but_better(philo->data->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork");
    }
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal_time = get_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->meal_mutex);
    print_status(philo, "is eating");
    usleep_but_better(philo->data->time_to_eat);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while(!is_dead(philo->data))
	{
		eat(philo);
		print_status(philo, "is sleeping");
		usleep_but_better(philo->data->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return NULL;
}

void	*monitor_routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	while(!is_dead(data))
	{
		if(death_check(data) || did_eat_all(data))
			return NULL;
		usleep_but_better(500);
	}
	return NULL;
}


//fix thinking stuff
//after die program keeps print it should stop