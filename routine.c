/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:08:20 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/12 18:50:54 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_flag(t_rules *rules)
{
	if (rules->dead_flag == 1)
		return (1);
	return (0);
}

void	philo_eat();

void	philo_sleep();

void	philo_think();

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_rules	*dead;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(1);
	while (check_dead_flag(dead))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
