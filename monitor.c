/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:47:05 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/10 18:02:59 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//return 1 = close
//return 0 = continue

#include "philo.h"

int	check_dead(t_rules *rules, int i)
{
	if (gettime() - rules->philo[i].last_meal > rules->philo[i].t_die)
	{
		pthread_mutex_lock(&rules->philo[i].print);
		printf("%d %d died\n", gettime() - rules->philo[i].t_start, i + 1);
		rules->dead_flag = 1;
		return (1);
	}
	return (0);
}

int	end_meals(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philo->nb_philo)
	{
		if (rules->philo[i].meals_count < rules->philo[i].nb_meals)
			return (0);
		i++;
	}
	return (1);
}

void	monitor(t_rules *rules)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < rules->philo->nb_philo)
		{
			if (check_dead(rules, i))
				return ;
			i++;
		}
		if (end_meals(rules))
			return ;
	}
}
