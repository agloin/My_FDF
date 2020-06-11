/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:30:42 by agloin            #+#    #+#             */
/*   Updated: 2019/09/24 20:18:42 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)source;
	d = (unsigned char *)dest;
	i = 0;
	if (d == s || n == 0)
		return (d);
	while (n-- > 0)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
