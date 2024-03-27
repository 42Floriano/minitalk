/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:19:04 by falberti          #+#    #+#             */
/*   Updated: 2024/03/27 13:50:48 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_var	g_char;

static void	read_bit(int signum)
{
	g_char.c += ((signum & 1) << g_char.i);
	g_char.i += 1;
	if (g_char.i == 7)
	{
		ft_printf("%c", g_char.c);
		if (g_char.c == '\0')
			ft_printf("\n");
		g_char.i = 0;
		g_char.c = 0;
	}
}

int	main(void)
{
	g_char.i = 0;
	g_char.c = 0;
	ft_printf("Welcome to Floriano's Server!\n");
	ft_printf("My Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, read_bit);
		signal(SIGUSR1, read_bit);
		pause();
	}
	return (0);
}
