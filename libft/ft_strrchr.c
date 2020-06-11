/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:56:17 by agloin            #+#    #+#             */
/*   Updated: 2019/09/14 15:27:32 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *last;

	last = NULL;
	while (*str)
	{
		if (*str == ch)
			last = (char *)str;
		str++;
	}
	if (*str == ch)
		return ((char *)str);
	return (last);
}
