/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:47:05 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/31 20:46:14 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_rules *philo, int i)
{
	t_philo	*philos;

	philos = philo->philo;
	if (gettime() - philo->philo[i].last_meal > philo->philo[i].t_die)
	{
		print(gettime() - philo->philo[i].t_start, i + 1, " died\n", philos);
		philo->dead = 1;
		return (1);
	}
	return (0);
}

int	end_meals(t_rules *philo)
{
	int	i;

	i = 0;
	while (i < philo[i].nb_philo)
	{
		if (philo->philo[i].meals_count < philo->philo[i].nb_meals)
			return (0);
		i++;
	}
	return (1);
}

void	*monitor(void *arg)
{
	t_rules	*monitor;
	int		i;

	monitor = (t_rules *)arg;
	while (monitor->dead == 0)
	{
		i = 0;
		while (i < monitor->nb_philo)
		{
			if (check_dead(monitor, i) == 1)
			{
				monitor->dead = 1;
				break ;
			}
			i++;
		}
		if (end_meals(monitor) && monitor->philo[0].nb_meals != -1)
			monitor->dead = 1;
	}
	return (arg);
}
