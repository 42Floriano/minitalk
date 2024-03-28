/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:19:04 by falberti          #+#    #+#             */
/*   Updated: 2024/03/28 12:39:57 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_var	g_char;

static void	read_bit(int signum, siginfo_t *info, void *ucontent)
{
	g_char.c += ((signum & 1) << g_char.i);
	g_char.i += 1;
	(void)ucontent;
	(void)info;
	if (g_char.i == 7)
	{
		write(1, &g_char.c, 1);
		if (g_char.c == '\0')
		{
			write(1, "\n", 1);
			usleep(10000);
			kill(info->si_pid, SIGUSR2);
		}
		g_char.i = 0;
		g_char.c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_char.i = 0;
	g_char.c = 0;
	sa.sa_sigaction = &read_bit;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("Welcome to Floriano's Server!\n");
	ft_printf("My Server PID is: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		pause();
	}
	return (0);
}
