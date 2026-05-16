/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:03:44 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/05/16 21:53:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	ft_atol(const char *nptr)
{
	int	sign;
	long long	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	if (result > (2147483647 - (nptr[i] - '0')) / 10)
		return (-1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9') || result > 2147483647)
			return -1;
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
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