/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:35:23 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/05/26 13:17:03 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>

typedef struct s_data
{
    int                 num_philos;
    long                time_to_die;
    long                time_to_eat;
    long                time_to_sleep;
    int                 must_eat_count;
    long                start_time;
    int                 someone_died;
    pthread_mutex_t     death_mutex;
    pthread_mutex_t     print_mutex;
    pthread_mutex_t     *forks;
    struct s_philo      *philos;
}   t_data;

typedef struct s_philo
{
    int                 id;
    long                last_meal_time;
    int                 meals_eaten;
    pthread_mutex_t     meal_mutex;
    pthread_mutex_t     *left_fork;
    pthread_mutex_t     *right_fork;
    pthread_t           thread;
    t_data              *data;
}   t_philo;


int		init_data(t_data *data);
void		nuke(t_data *data);

long		get_time(void);
void		print_status(t_philo *philo, char *msg);
int			is_dead(t_data *data);
int			death_check(t_data *data);
int			did_eat_all(t_data *data);

void		*routine(void *arg);
void		*monitor_routine(void *arg);

void		set_data(t_data *data, char **argv);
int			is_valid(char **argv, int argc);

#endif