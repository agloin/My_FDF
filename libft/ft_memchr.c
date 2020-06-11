/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:36:01 by agloin            #+#    #+#             */
/*   Updated: 2019/09/15 16:08:09 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ar;
	size_t			i;

	ar = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (ar[i] == (unsigned char)c)
			return (ar + i);
		i++;
	}
	return (NULL);
}
