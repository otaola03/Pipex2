/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:57:28 by jperez            #+#    #+#             */
/*   Updated: 2022/11/18 20:38:14 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_here_doc(t_input *input)
{
	char	*entry;

	while (1)
	{
		entry = get_next_line(0);
		if (!ft_strncmp(entry, input->delimiter, ft_strlen(input->delimiter)))
		{
			free(entry);
			break ;
		}
		write(input->pipes[0][WRITE], entry, ft_strlen(entry) - 1);
		write(input->pipes[0][WRITE], "\n", 1);
		free(entry);
	}
}
