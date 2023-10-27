/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:10:29 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/27 19:14:12 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	threads(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_create(&rules->god, NULL, &monitor, rules->philo))
		return (1);
	while (i < philo->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL,
				&routine, &philo[i]))
			return (1);
		i++;
	}
	i = 0;
	if (pthread_join(rules->god, NULL))
		return (1);
	while (i < philo->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}
