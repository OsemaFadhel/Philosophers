/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:54:13 by ofadhel           #+#    #+#             */
/*   Updated: 2023/05/31 17:01:03 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct s_philo
{
	int	philos;
	int	ttd;
	int	tte;
	int	tts;
	int	times_eat;

}				t_philo;

int	ft_atoi(const char	*str);

void	init(t_philo *philo, int ac, char **av);
int		check_args(int ac, char **av);

#endif
