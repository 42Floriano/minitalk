/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:19:40 by falberti          #+#    #+#             */
/*   Updated: 2024/03/19 16:56:53 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
			{
				printf("1");
				kill(pid, SIGUSR2);	
			}
			else
			{
				printf("0");
				kill(pid, SIGUSR1);	
			}
			shift++;
			usleep(500);
		}
		i++;
	}
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
		send_signal(pid, str);
		ft_printf("Message succesfully sent !!\n");
	}
	else
	{
		ft_printf("Arguments incorrect !!\n");
		ft_printf("Please enter the PID and one string\n");
	}
	return (0);
}
