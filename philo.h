/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:32:38 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/12 19:00:15 by ofadhel          ###   ########.fr       */
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

//structures

typedef struct s_philo
{
	int				id;
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				is_eating;
	int				dead;
	int				nb_meals;
	int				meals_count;
	int				last_meal;
	int				t_start;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*print;
}				t_philo;

typedef struct s_rules
{
	int				dead_flag;
	t_philo			*philo;
}				t_rules;

//-------------functions-----------------

//utils

int				gettime(void);

//monitor

int				check_dead(t_rules *rules, int i);
int				end_meals(t_rules *rules);
void			monitor(t_rules *rules);

//routine

#endif
