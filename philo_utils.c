/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:55:35 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/05/16 16:40:38 by marvin           ###   ########.fr       */
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