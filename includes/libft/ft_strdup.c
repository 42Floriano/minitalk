/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:32:44 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:16:37 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strr;
	int		size;
	int		i;

	size = ft_strlen(s1);
	strr = malloc((size +1) * sizeof(char));
	if (!strr)
		return (strr);
	i = 0;
	while (s1[i])
	{
		strr[i] = s1[i];
		i++;
	}
	strr[i] = '\0';
	if (strr == NULL)
		return (strr);
	return (strr);
}
