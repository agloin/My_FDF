/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:42:23 by agloin            #+#    #+#             */
/*   Updated: 2019/09/25 05:00:16 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	if (!s || !(s1 = ft_strnew(ft_strlen(s))))
		return (NULL);
	ft_bzero(s1, ft_strlen((char *)s) + 1);
	i = 0;
	while (s[i])
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	return (s1);
}
