/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:39:12 by agloin            #+#    #+#             */
/*   Updated: 2019/09/12 23:11:23 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	const unsigned char	*ar1;
	const unsigned char	*ar2;

	ar1 = (const unsigned char *)arr1;
	ar2 = (const unsigned char *)arr2;
	if (ar1 == ar2 || n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*ar1 != *ar2)
			return (*ar1 - *ar2);
		ar1++;
		ar2++;
	}
	return (0);
}
