/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:47:05 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/28 00:10:43 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//return 1 = close
//return 0 = continue

#include "philo.h"

int	check_dead(t_rules *philo, int i)
{
	t_philo	*philos;

	philos = philo->philo;
	printf("check dead %d\n", philo->dead_flag);
	printf("hello %d\n", gettime() - philo->philo[i].last_meal);
	if (gettime() - philo->philo[i].last_meal > philo->philo[i].t_die)
	{
		print(gettime() - philo->philo[i].t_start, i + 1, " died\n", philos);
		printf("check dead 2 %d\n", philo->dead_flag);
		philo->dead_flag = 1;
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
			return (1);
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_rules	*monitor;
	int		i;
	int		flag;

	monitor = (t_rules *)arg;
	printf("monitor %d\n", monitor->dead_flag);
	while (monitor->dead_flag == 0)
	{
		i = 0;
		while (i < monitor->nb_philo)
		{
			if (check_dead(monitor, i) == 1)
			{
				printf("ciao\n");
				monitor->dead_flag = 1;
				break ;
			}
			i++;
		}
		if (end_meals(monitor))
			monitor->dead_flag = 1;
	}
	printf("monitor %d\n", monitor->dead_flag);
	return (arg);
}
