/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:36:14 by jperez            #+#    #+#             */
/*   Updated: 2022/11/19 19:55:53 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	c[2];
	char	*buf;
	char	*aux;

	rd = 1;
	i = 0;
	buf = (char *)malloc(sizeof(char) * 1);
	buf[0] = '\0';
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		c[rd] = '\0';
		aux = buf;
		buf = ft_strjoin(buf, c);
		free(aux);
		i++;
		if (c[0] == '\n')
			break ;
	}
	if ((!buf[i - 1] && !rd) || rd == -1)
		return (free(buf), NULL);
	return (buf);
}
