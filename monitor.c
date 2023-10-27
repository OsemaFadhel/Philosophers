/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:47:05 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/27 19:33:33 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//return 1 = close
//return 0 = continue

#include "philo.h"

int	check_dead(t_philo *philo, int i)
{
	if (gettime() - philo[i].last_meal > philo[i].t_die)
	{
		printf("%d\n", philo[i].t_die);
		printf("%d\n", gettime() - philo[i].last_meal);
		print(gettime() - philo[i].t_start, i + 1, " died\n", philo);
		philo[i].dead = 1;
		return (1);
	}
	return (0);
}

int	end_meals(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[i].nb_philo)
	{
		if (philo[i].meals_count < philo[i].nb_meals)
			return (1);
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*monitor;
	int		i;
	int		flag;

	flag = 0;
	monitor = (t_philo *)arg;
	while (flag == 0)
	{
		i = 0;
		while (i < monitor->nb_philo)
		{
			if (check_dead(monitor, i))
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (end_meals(monitor))
			flag = 1;
	}
	printf("end monitor\n");
	return (arg);
}
