/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 09:09:42 by agloin            #+#    #+#             */
/*   Updated: 2019/09/25 22:17:38 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *strb, const char *stra)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*stra)
		return ((char *)strb);
	while (strb[i])
	{
		j = 0;
		while (stra[j] != '\0' && strb[i + j] == stra[j])
			j++;
		if (stra[j] == '\0')
			return ((char *)&strb[i]);
		i++;
	}
	return (NULL);
}
