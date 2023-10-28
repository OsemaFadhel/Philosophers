/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:08:20 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/28 20:37:49 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_flag(t_philo *rules)
{
	if (*rules->dead == 1)
		return (1);
	return (0);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print(gettime() - philo->t_start, philo->id,
		" has taken a fork\n", philo);
	if (philo->nb_philo == 1)
	{
		ft_usleep(philo->t_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print(gettime() - philo->t_start, philo->id,
		" has taken a fork\n", philo);
	print(gettime() - philo->t_start, philo->id, " is eating\n", philo);
	philo->last_meal = gettime();
	ft_usleep(philo->t_eat);
	philo->meals_count++;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_sleep(t_philo	*philo)
{
	print(gettime() - philo->t_start, philo->id, " is sleeping\n", philo);
	ft_usleep(philo->t_sleep);
}

void	philo_think(t_philo *philo)
{
	print(gettime() - philo->t_start, philo->id, " is thinking\n", philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(1);
	while (check_dead_flag(philo) == 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
