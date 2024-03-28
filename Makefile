# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falberti <falberti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 12:00:27 by falberti          #+#    #+#              #
#    Updated: 2024/03/28 12:55:52 by falberti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
LIBRARY = includes
SOURCES = sources
BSOURCES = sources_bonus

HEADER = $(LIBRARY)/minitalk.h

CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER) -g
LIBFT = includes/libft/libftxl.a

## -fsanitize=address
all: $(LIBFT)
	$(CC) $(CFLAGS) $(SOURCES)/server.c  $(LIBFT) -o server
	$(CC) $(CFLAGS) $(SOURCES)/client.c $(LIBFT)  -o client

$(LIBFT):
	$(MAKE) -C includes/libft

clean:
	$(MAKE) -C includes/libft clean

fclean: clean
	$(MAKE) -C includes/libft fclean
	rm -f server client

bonus: $(LIBFT)
	$(CC) $(CFLAGS) $(BSOURCES)/server_bonus.c  $(LIBFT) -o server
	$(CC) $(CFLAGS) $(BSOURCES)/client_bonus.c $(LIBFT)  -o client

re: fclean all

bre: fclean bonus

.PHONY: all clean fclean re bonus bre