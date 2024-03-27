/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:19:40 by falberti          #+#    #+#             */
/*   Updated: 2024/03/27 18:10:00 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	msg_rcved(int signum)
{
	(void)signum;
	write(1, "Message received succesfully!\n", 31);
	exit(0);
}

static	int	check_av(char **av)
{
	int	i;

	i = 0;
	if (ft_strlen(av[1]) == 0 || ft_strlen(av[2]) == 0)
		return (0);
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i]))
			return (0);
		i++;
	}
	return (1);
}

static	void	send_signal(int pid, char *str)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	shift;

	len = (unsigned int)ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(500);
		}
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	int					pid;
	char				*str;
	struct sigaction	sa;

	if (ac == 3 && check_av(av))
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		sa.sa_handler = &msg_rcved;
		send_signal(pid, str);
		ft_printf("Message sent succesfully!\n");
		while (1)
		{
			sigaction(SIGUSR2, &sa, NULL);
			usleep(100000);
			return (1);
		}
	}
	else
	{
		ft_printf("Arguments incorrect!\n");
		ft_printf("Please enter the PID and one non-empty string.\n");
	}
	return (0);
}
