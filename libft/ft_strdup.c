/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:09:03 by agloin            #+#    #+#             */
/*   Updated: 2019/09/25 22:05:35 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char		*mass;
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	if (!(mass = (char*)malloc(sizeof(*mass) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		mass[i] = str[i];
		i++;
	}
	mass[i] = '\0';
	return (mass);
}
