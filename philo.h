/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:32:38 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/09 00:00:52 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	int				is_eating;
	int				is_sleeping;
	int				is_thinking;
	int				is_dead;
	int				nb_meals;
	int				last_meal;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*print;

}				t_philo;

typedef struct s_rules
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	t_philo			*philo;
}				t_rules;

#endif
