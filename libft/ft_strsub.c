/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 09:58:52 by agloin            #+#    #+#             */
/*   Updated: 2019/09/20 18:52:41 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*mass;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!(mass = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len--)
	{
		mass[i] = s[start];
		i++;
		start++;
	}
	mass[i] = '\0';
	return (mass);
}
