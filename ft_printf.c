/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:10:42 by slaajour          #+#    #+#             */
/*   Updated: 2022/05/11 20:33:00 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	lots_of_if(char s, va_list args)
{
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start (args, str);
	i = 0;
	g_variable = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			lots_of_if(str[i], args);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (g_variable);
}
