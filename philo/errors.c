/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:00:23 by ofadhel           #+#    #+#             */
/*   Updated: 2023/11/03 17:45:31 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (c);
	}
	return (0);
}

int	check_errors(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (ft_atoi(argv[1]) > 200)
	{
		printf("Not more than 200 philos, pls.\n");
		return (1);
	}
	while (i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Error: Invalid argument\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}
