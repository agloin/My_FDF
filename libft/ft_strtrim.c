/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:15:11 by agloin            #+#    #+#             */
/*   Updated: 2019/09/25 22:37:03 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		k;
	size_t		len;

	k = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[k] == ' ' || s[k] == '\t' || s[k] == '\n')
		k++;
	while ((k < len) && (s[len - 1] == ' ' || s[len - 1] == '\t'
				|| s[len - 1] == '\n'))
		len--;
	return (ft_strsub(s, k, (len - k)));
}
