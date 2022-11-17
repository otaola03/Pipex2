/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:31:00 by jperez            #+#    #+#             */
/*   Updated: 2022/11/06 13:22:26 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_keep_file_in_pipe(t_input *input)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(input->infile, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		ft_general_free(input);
		exit(-1);
	}
	ft_dup2(fd, input->pipes[0][READ], input);
	ft_close(fd, input);
}

void	ft_keep_pipe_in_file(t_input *input, int doc_on)
{
	int	fd;

	if (doc_on == 1)
		fd = open(input->outfile, O_CREAT | O_WRONLY | O_APPEND, 0660);
	else
		fd = open(input->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (fd == -1)
	{
		perror("");
		ft_general_free(input);
		exit(-1);
	}
	ft_dup2(fd, STDOUT_FILENO, input);
	ft_close(fd, input);
}
