/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:55:34 by agloin            #+#    #+#             */
/*   Updated: 2019/09/17 15:30:06 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)source;
	i = 0;
	if (d == s || n == 0)
		return (d);
	if (s < d)
		while (i++ < n)
			d[n - i] = s[n - i];
	else
		while (n-- > 0)
			*(d++) = *(s++);
	return (dest);
}
