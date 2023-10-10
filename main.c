/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:32:41 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/10 17:01:43 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_rules(t_rules *rules, int ac, char **av)
{
	rules->nb_philo = ft_atoi(av[1]);
	rules->t_die = ft_atoi(av[2]);
	rules->t_eat = ft_atoi(av[3]);
	rules->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules->nb_eat = ft_atoi(av[5]);
	else
		rules->nb_eat = -1;
	if (rules->nb_philo < 1 || rules->nb_philo > 200 || rules->t_die < 60
		|| rules->t_eat < 60 || rules->t_sleep < 60 || rules->nb_eat < -1)
	{
		printf("Error: Invalid argument\n");
		return (0);
	}
	return (1);
}

/*int	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	if (!rules->forks)
		return (0);
	while (i < rules->nb_philo)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&rules->print, NULL);
	rules->philo = malloc(sizeof(t_philo) * rules->nb_philo);
	if (!rules->philo)
		return (0);
	i = 0;
	while (i < rules->nb_philo)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].t_die = rules->t_die;
		rules->philo[i].t_eat = rules->t_eat;
		rules->philo[i].t_sleep = rules->t_sleep;
		rules->philo[i].nb_eat = rules->nb_eat;
		rules->philo[i].r_fork = &rules->forks[i];
		rules->philo[i].l_fork = &rules->forks[(i + 1) % rules->nb_philo];
		i++;
	}
	return (1);
}*/

int	main(int ac, char **av)
{
	t_rules	rules;

	if (ac == 5 || ac == 6)
	{
		if (!check_errors(ac, av))
			return (0);
		if (!init(&rules, ac, av))
			return (0);
		if (!start_threads(&rules))
			return (0);
	}
}
