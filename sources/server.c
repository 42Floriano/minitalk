/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:19:04 by falberti          #+#    #+#             */
/*   Updated: 2024/03/19 17:19:50 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// static g_var	g_char;

// static void	read_bit(int signum)
// {
// 	printf("%d", signum);
// 	g_char.i = 0;
// 	g_char.c += ((signum & 1) << g_char.i);
// 	g_char.i++;
// 	if (g_char.i == 7)
// 	{
// 		ft_printf("%c", g_char.c);
// 		if (g_char.c == '\0')
// 			ft_printf("\n");
// 		g_char.i = 0;
// 		g_char.c = 0;
// 	}
// }

void	test(int i)
{
	printf("Test: %d", i);
	return ;
}

int	main(void)
{
	ft_printf("Welcome to Floriano's Server!\n");
	ft_printf("My Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, test);
		signal(SIGUSR1, test);
		pause();
	}
	return (0);
}
