/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:38:27 by ofadhel           #+#    #+#             */
/*   Updated: 2023/06/03 13:49:22 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philos)
	{
		pthread_create(&philo->thread[i], NULL, &routine, philo);
		i++;
	}
}

void	*routine(void *arg)
{
}
