/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:10:33 by agloin            #+#    #+#             */
/*   Updated: 2019/09/24 15:35:20 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnew(size_t size)
{
	void *mass;

	if (size + 1 == 0)
		return (0);
	if (!(mass = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(mass, size + 1);
	return (mass);
}
