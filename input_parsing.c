/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:03:44 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/05/25 11:36:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atol(const char *nptr)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (-1);
		if (result > (2147483647 - (nptr[i] - '0')) / 10)
			return (-1);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result);
}

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

int is_valid(char **argv, int argc)
{
	int	i;

    i = 1;
	while(i < argc)
	{
		if (ft_atol(argv[i]) <= 0)
			return 0;
		i++;
	}
	return 1;
}