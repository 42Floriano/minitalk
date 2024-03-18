# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falberti <falberti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 12:00:27 by falberti          #+#    #+#              #
#    Updated: 2024/03/18 12:14:04 by falberti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
SOURCES_DIR = sources
LIBRARY = includes

HEADER = $(LIBRARY)/minitalk.h

FILES = $(SOURCES_DIR)/server.c\
				$(SOURCES_DIR)/client.c\

CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))

####################################################################
## Varguments
CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER) -g
NAME = minitalk
LIBFT = includes/libft/libftxl.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C includes/libft

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(OFILES) $(LIBFT) -fsanitize=address -o $(NAME)

$(FILES).o: $(FILES).c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C includes/libft clean
	rm -f $(OFILES)

fclean: clean
	$(MAKE) -C includes/libft fclean
	rm -f $(NAME)	

re: fclean all

.PHONY all clean fclean re