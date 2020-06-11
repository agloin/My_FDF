/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:33:47 by agloin            #+#    #+#             */
/*   Updated: 2019/09/19 16:45:27 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	result;
	int			n;
	int			i;

	n = 1;
	i = 0;
	result = 0;
	while ((str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\f'
				|| str[i] == '\n' || str[i] == ' '))
		i++;
	if (str[i] == '-')
		n = -n;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result * n < 0 && n > 0)
		return (-1);
	if (result * n > 0 && n < 0)
		return (0);
	return (result * n);
}
