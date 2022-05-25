# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 00:45:59 by slaajour          #+#    #+#              #
#    Updated: 2022/05/11 23:05:07 by slaajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
SERVER_NAME_BONUS = server_bonus
CLIENT_NAME_BONUS = client_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror
SERVER_SRCS = server.c ft_printf.c ft_putchar.c ft_putnbr.c
CLIENT_SRCS = client.c ft_printf.c ft_atoi.c ft_putchar.c ft_putnbr.c
SERVER_BONUS_SRCS = server_bonus.c ft_printf.c ft_putchar.c ft_putnbr.c
CLIENT_BONUS_SRCS = client_bonus.c ft_printf.c ft_atoi.c ft_putchar.c ft_putnbr.c

NAME = minitalk

$(NAME) : $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

$(SERVER_NAME) :
	@$(CC) $(FLAGS) -o $(SERVER_NAME) $(SERVER_SRCS)
$(CLIENT_NAME) :
	@$(CC) $(FLAGS) -o $(CLIENT_NAME) $(CLIENT_SRCS)
$(SERVER_NAME_BONUS) :
	@$(CC) $(FLAGS) -o $(SERVER_NAME_BONUS) $(SERVER_BONUS_SRCS)
$(CLIENT_NAME_BONUS) :
	@$(CC) $(FLAGS) -o $(CLIENT_NAME_BONUS) $(CLIENT_BONUS_SRCS)
all : $(NAME)

.c.o :
		@$(CC) $(FLAGS) -c $<
clean :
	@rm -f $(CLIENT_NAME) $(SERVER_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

fclean: clean

re: fclean all


.PHONY: all clean fclean re