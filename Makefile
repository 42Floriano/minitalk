# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falberti <falberti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 12:00:27 by falberti          #+#    #+#              #
#    Updated: 2024/03/18 14:24:07 by falberti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
LIBRARY = includes
SOURCES = sources

HEADER = $(LIBRARY)/minitalk.h

CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER) -g
LIBFT = includes/libft/libftxl.a

all: $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=address $(SOURCES)/server.c  $(LIBFT) -o server
	$(CC) $(CFLAGS) -fsanitize=address $(SOURCES)/client.c $(LIBFT)  -o client

$(LIBFT):
	$(MAKE) -C includes/libft

clean:
	$(MAKE) -C includes/libft clean

fclean: clean
	$(MAKE) -C includes/libft fclean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re