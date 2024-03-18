/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:19:40 by falberti          #+#    #+#             */
/*   Updated: 2024/03/18 14:26:01 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static	void	send_signal(int pid, char *str, size_t len)
{
	ft_printf("PID: %d\nSTR: %s\nSizeSTR: %d", pid, str, len);
	return ;
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		send_signal(pid, str, ft_strlen(str));
	}
	else
	{
		ft_printf("Arguments incorrect please enter one word string and one int PID\n");
	}
	return (0);
}
