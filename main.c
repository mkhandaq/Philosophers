/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:56:05 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/05/23 03:01:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_data(t_data *data, char **argv)
{
	data->num_philos = (int)ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->must_eat_count = ft_atol(argv[5]);
	else
		data->must_eat_count = -1;
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc > 6 || argc < 5 || !is_valid(argv, argc))
	{
		printf("Invalid input\n");
		return (1);
	}
	set_data(&data, argv);
	return (0);
}
