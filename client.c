/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:34:28 by slaajour          #+#    #+#             */
/*   Updated: 2022/05/11 23:17:30 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	shifting(int i, int id)
{
	int	j;
	int	bit;

	j = 7;
	while (j >= 0)
	{
		bit = i >> j & 1;
		if (bit == 0)
			kill(id, SIGUSR2);
		if (bit == 1)
			kill(id, SIGUSR1);
		usleep(100);
		j--;
	}
}

void	converting(char *str, int id)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i])
	{
		a = (int)str[i];
		shifting(a, id);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	id;

	if (ac == 3)
	{
		id = ft_atoi(av[1]);
		converting(av[2], id);
	}
}
