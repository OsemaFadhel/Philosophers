/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:03:30 by ofadhel           #+#    #+#             */
/*   Updated: 2023/05/31 17:05:58 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(t_philo *philo, int ac, char **av)
{
	philo->philos = ft_atoi(av[1]);
	philo->ttd = ft_atoi(av[2]);
	philo->tte = ft_atoi(av[3]);
	philo->tts = ft_atoi(av[4]);
	if (ac == 6)
		philo->times_eat = ft_atoi(av[5]);
	else
		philo->times_eat = -1;
}
int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac == 5 || ac == 6)
	{
		if (!check_args(ac, av))
		{
			printf("ERROR: Only numbers\n");
			return (1);
		}
		init(&philo, ac, av);
		//start(&philo);
	}
	else
		printf("Error: Invalid number of arguments\n");
	return (0);
}
