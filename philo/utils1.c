/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:03:17 by ofadhel           #+#    #+#             */
/*   Updated: 2023/10/28 19:13:00 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char	*str)
{
	int					i;
	int					neg;
	unsigned long int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	return (num * neg);
}

void	print(int time, int i, char *message, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (*philo->dead == 0)
		printf("%d %d %s", time, i, message);
	pthread_mutex_unlock(philo->print);
}

int	ft_usleep(int time)
{
	int	start;

	start = gettime();
	while (gettime() - start < time)
		usleep(100);
	return (1);
}

int	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
