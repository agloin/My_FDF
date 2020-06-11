/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:34:23 by agloin            #+#    #+#             */
/*   Updated: 2019/09/19 14:22:17 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char *b;

	b = (unsigned char *)dest;
	while (n-- > 0)
	{
		*b = (unsigned char)c;
		b++;
	}
	return (dest);
}
