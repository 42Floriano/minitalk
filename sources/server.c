/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:19:04 by falberti          #+#    #+#             */
/*   Updated: 2024/03/18 14:35:49 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	test(int test)
{
	ft_printf("test: %d", test);
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
