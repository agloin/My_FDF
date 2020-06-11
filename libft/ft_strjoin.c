/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:42:54 by agloin            #+#    #+#             */
/*   Updated: 2019/09/25 22:35:27 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mass;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(mass = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		mass[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		mass[i + j] = s2[j];
		j++;
	}
	mass[i + j] = '\0';
	return (mass);
}
