/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 13:07:36 by agloin            #+#    #+#             */
/*   Updated: 2020/06/15 19:05:36 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

float	ft_max1(float a, float b)
{
    if (a > b)
        return (a);
    return (b);
}

float	ft_mod(float a)
{
    if (a < 0)
        return (-a);
    return (a);
}
