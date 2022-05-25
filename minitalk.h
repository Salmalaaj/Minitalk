/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 00:14:00 by slaajour          #+#    #+#             */
/*   Updated: 2022/05/11 20:32:22 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdarg.h>
# include <math.h>

int	g_variable;
void	sig_handler(int sig);
void	shifting(int i, int id);
void	converting(char *str, int id);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(long long num);
void	contraire(void);
void	lots_of_if(char s, va_list args);
int		ft_printf(const char *str, ...);

#endif