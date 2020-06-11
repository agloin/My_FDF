/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:13:07 by agloin            #+#    #+#             */
/*   Updated: 2019/10/20 20:31:14 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "fcntl.h"
# include "sys/types.h"
# include "unistd.h"
# include "stdlib.h"
# include "libft.h"
# define BUFF_SIZE 6

int		get_next_line(const int fd, char **line);

#endif
