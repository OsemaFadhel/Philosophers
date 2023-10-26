/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:10:29 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/26 17:01:51 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	threads(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	printf("threads\n");
	if (pthread_create(&rules->god, NULL, &monitor, rules))
		return (1);
	while (i < philo[0]->nb_philo)
	{
		printf("thread philo %d\n", philo[i].id);
		if (pthread_create(&philo[i].thread, NULL,
				&routine, &philo[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < philo[0]->nb_philo)
	{
		//pthread join...;
	}
	return (0);
}
