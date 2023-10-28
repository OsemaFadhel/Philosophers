/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:32:41 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/28 04:26:19 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_rules *rules, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return ;
		i++;
	}
}

void	init_2(t_rules *rules, t_philo *philo, int i, char **av)
{
	philo[i].nb_philo = ft_atoi(av[1]);
	philo[i].t_die = ft_atoi(av[2]);
	philo[i].t_eat = ft_atoi(av[3]);
	philo[i].t_sleep = ft_atoi(av[4]);
	philo[i].r_fork = &rules->forks[i];
	if (i == 0)
		philo[i].l_fork = &rules->forks[philo[i].nb_philo - 1];
	else
		philo[i].l_fork = &rules->forks[i - 1];
}

int	init(t_rules *rules, t_philo *philo, char **av)
{
	int	i;

	rules->dead = 0;
	rules->nb_philo = ft_atoi(av[1]);
	if (pthread_mutex_init(&rules->print, NULL))
		return (1);
	forks_init(rules, ft_atoi(av[1]));
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		init_2(rules, philo, i, av);
		philo[i].is_eating = 0;
		philo[i].dead = &rules->dead;
		if (av[5])
			philo[i].nb_meals = ft_atoi(av[5]);
		else
			philo[i].nb_meals = -1;
		philo[i].meals_count = 0;
		philo[i].last_meal = gettime();
		philo[i].t_start = gettime();
		philo[i].print = &rules->print;
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_rules	rules;
	t_philo	philo[MAX_PHILOSOPHERS];

	rules.philo = philo;
	if (ac == 5 || ac == 6)
	{
		gettime();
		if (init(&rules, philo, av) == 1)
			return (1);
		if (threads(&rules, philo))
			return (1);
	}
	else
		printf("Error: wrong number of arguments\n");
}
