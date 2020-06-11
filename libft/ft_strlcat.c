/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:20:31 by agloin            #+#    #+#             */
/*   Updated: 2019/09/25 20:51:00 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *app, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		res;

	i = 0;
	j = 0;
	res = 0;
	while (dest[i] != '\0')
		i++;
	while (app[res] != '\0')
		res++;
	if (i >= len)
		res += len;
	else
		res += i;
	while (app[j] != '\0' && i + 1 < len)
	{
		dest[i] = app[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}
