/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:47:05 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/26 16:48:56 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//return 1 = close
//return 0 = continue

//maybe create a print function so there will not be data races
//				printf("%d...", time, id, message(eat, dead...));
#include "philo.h"

int	check_dead(t_rules *rules, int i)
{
	if (gettime() - rules->philo[i].last_meal > rules->philo[i].t_die)
	{
		pthread_mutex_lock(rules->philo[i].print);
		print(gettime() - rules->philo[i].t_start, i + 1, " died\n", rules);
		rules->dead_flag = 1;
		return (1);
	}
	return (0);
}

int	end_meals(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philo[i]->nb_philo)
	{
		if (rules->philo[i].meals_count < rules->philo[i].nb_meals)
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

	flag = 0;
	monitor = (t_rules *)arg;
	while (1)
	{
		i = 0;
		while (i < monitor->philo[0]->nb_philo)
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
		if (flag == 1)
			break ;
	}
	return (arg);
}
