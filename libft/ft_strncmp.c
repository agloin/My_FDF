/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:13:59 by agloin            #+#    #+#             */
/*   Updated: 2019/09/25 22:31:36 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while ((i < (n - 1)) && ((unsigned char)str1[i]
				== (unsigned char)str2[i]) && (unsigned char)str1[i] != '\0'
			&& (unsigned char)str2[i] != '\0')
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
