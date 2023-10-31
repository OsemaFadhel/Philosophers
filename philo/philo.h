/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:32:38 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/28 04:17:34 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//libraries

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILOSOPHERS 200

//structures

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				nb_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				is_eating;
	int				*dead;
	long			nb_meals;
	int				meals_count;
	int				last_meal;
	int				t_start;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*print;
}				t_philo;

typedef struct s_rules
{
	pthread_t		god;
	int				nb_philo;
	int				dead;
	pthread_mutex_t	print;
	pthread_mutex_t	forks[MAX_PHILOSOPHERS];
	t_philo			*philo;
}				t_rules;

//-------------functions-----------------

//utils

int				gettime(void);
int				ft_usleep(int time);
void			print(int time, int i, char *message, t_philo *rules);
int				ft_atoi(const char	*str);

//threads

int				threads(t_rules *monitor, t_philo *philo);

//monitor

int				check_dead(t_rules *philo, int i);
int				end_meals(t_rules *philo);
void			*monitor(void *arg);

//routine

int				check_dead_flag(t_philo *rules);
void			*routine(void *arg);
void			philo_eat(t_philo *philo);

#endif
