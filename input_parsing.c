/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:03:44 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/04/30 12:19:47 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.c"

static long long	ft_atoi(const char *nptr)
{
	int	sign;
	long long	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
        if (!(nptr[i] >= '0' && nptr[i] <= '9') || result > 2147483647)
            return -1;
	}
	return (result * sign);
}

int is_valid(char **argv)
{
	int	i;

    i = 0;
	while(argv && argv[i])
	{
		if (ft_atio(argv[i]) <= 0 || (ft_atio(argv[i]) > 2147483647))
			return 0;
	}
	return 1;
}