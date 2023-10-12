/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:32:41 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/12 19:36:07 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_philo *philo, char **av)
{
	int	i;

	i = 0;
	philo->nb_philo = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->nb_meals = ft_atoi(av[5]);
	else
		philo->nb_meals = -1;
	philo->meals_count = 0;
	philo->last_meal = 0;
	philo->t_start = 0;
	philo->dead = 0;
	philo->is_eating = 0;
	while (i < philo->nb_philo)
	{
		philo[i].id = i + 1;
	}
	//missing forks
}

int	main(int ac, char **av)
{
	t_rules	rules;
	t_philo philo;

	if (ac == 5 || ac == 6)
	{
		init(&philo, av);
		//missing mutexes
		//missing threads
	}
	else
		printf("Error: wrong number of arguments\n");
}
