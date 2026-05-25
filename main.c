/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:56:05 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/05/25 12:08:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	creat_threads(t_data *data, pthread_t *monitor)
{
	int	i;

	i = 0;
	while(i < data->num_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, routine, &data->philos[i]);
		i++;
	}
	pthread_create(monitor, NULL, monitor_routine, data);
}

int	main(int argc, char **argv)
{
	t_data 		data;
	pthread_t	monitor;
	int			i;

	memset(&data, 0, sizeof(t_data));
	if (argc > 6 || argc < 5 || !is_valid(argv, argc))
	{
		printf("Invalid input\n");
		return (1);
	}
	set_data(&data, argv);
	if (!init_data(&data))
	{
		nuke(&data);
		return (1);
	}
	data.start_time = get_time();
	i = 0;
	while (i < data.num_philos)
	{
		data.philos[i].last_meal_time = data.start_time;
		i++;
	}
	creat_threads(&data, &monitor);
	i = 0;
	while (i < data.num_philos)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	nuke(&data);
	return 0;
}
