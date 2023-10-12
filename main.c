/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:32:41 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/12 19:21:14 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_rules *philo, char **av)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if(av[5])
		philo->nb_meals = ft_atoi(av[5]);
	else
		philo->nb_meals = -1;
	
}

int	main(int ac, char **av)
{
	t_rules	rules;
	t_philo philo;




}
