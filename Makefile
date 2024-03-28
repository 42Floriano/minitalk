# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falberti <falberti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 12:00:27 by falberti          #+#    #+#              #
#    Updated: 2024/03/28 15:57:04 by falberti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
LIBRARY = includes
SOURCES = sources
BSOURCES = sources_bonus

HEADER = $(LIBRARY)/minitalk.h

FILES = $(SOURCES)/client\
				$(SOURCES)/server\

BFILES = $(BSOURCES)/client_bonus\
				$(BSOURCES)/server_bonus\

CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))

## Bonus
BCFILES = $(addsuffix .c, $(BFILES))
BOFILES = $(addsuffix .o, $(BFILES))

CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER)
LIBFT = includes/libft/libftxl.a
NAMES = server
NAMEC = client
BNAMES = server_bonus
BNAMEC = client_bonus

## -fsanitize=address

all: $(NAMES) $(NAMEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAMES): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(SOURCES)/server.o  $(LIBFT) -o $(NAMES)
	
$(NAMEC):
	$(CC) $(CFLAGS) $(SOURCES)/client.o $(LIBFT)  -o $(NAMEC)


# $(FILES).o: $(FILES).c
# 		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C includes/libft

clean:
	$(MAKE) -C includes/libft clean
	rm -f $(OFILES) $(BOFILES)

fclean: clean
	$(MAKE) -C includes/libft fclean
	rm -f server client server_bonus client_bonus


bonus: $(BNAMES) $(BNAMEC)

$(BNAMES): $(BOFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(BSOURCES)/server_bonus.o  $(LIBFT) -o $(BNAMES)
	
$(BNAMEC): 
	$(CC) $(CFLAGS) $(BSOURCES)/client_bonus.o $(LIBFT)  -o $(BNAMEC)

# $(BFILES).o: $(BFILES).c
# 		$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

bre: fclean bonus

.PHONY: all clean fclean re bonus bre