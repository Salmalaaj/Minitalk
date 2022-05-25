/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 08:24:01 by slaajour          #+#    #+#             */
/*   Updated: 2022/05/11 22:42:02 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct h_type
{
	int	*tab;
	int	i;

}	t_data;

t_data	g_data;

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_data.tab[g_data.i] = 1;
		g_data.i++;
	}
	if (sig == SIGUSR2)
	{
		g_data.tab[g_data.i] = 0;
		g_data.i++;
	}
}

void	contraire(void)
{
	int	j;
	int	power;
	int	var;

	j = 0;
	var = 0;
	power = 7;
	while (j < 8)
	{
		var += pow(2, power) * g_data.tab[j];
		j++;
		power--;
	}
	write(1, &var, 1);
}

int	main(void)
{
	g_data.tab = malloc(sizeof(int));
	g_data.i = 0;
	ft_printf("%d\n", getpid());
	signal(SIGUSR2, &sig_handler);
	signal(SIGUSR1, &sig_handler);
	while (1)
	{
		if (g_data.i == 8)
		{
			contraire();
			g_data.i = 0;
		}
		pause();
	}
	free(g_data.tab);
}
