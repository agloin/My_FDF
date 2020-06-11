/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:29:52 by agloin            #+#    #+#             */
/*   Updated: 2019/09/12 23:43:55 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	b;
	int				i;

	d = (unsigned char *)dest;
	s = (unsigned char *)source;
	b = (unsigned char)c;
	i = 0;
	while (n-- > 0)
	{
		d[i] = s[i];
		if (d[i] == b)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
