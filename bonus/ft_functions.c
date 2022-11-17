/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:33:32 by jperez            #+#    #+#             */
/*   Updated: 2022/11/02 19:32:48 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_pipe(int *fd, t_input *input)
{
	if (pipe(fd) == -1)
	{
		perror("");
		ft_general_free(input);
		exit(-1);
	}
}

void	ft_dup2(int fd1, int fd2, t_input *input)
{
	if (dup2(fd1, fd2) == -1)
	{
		perror("");
		ft_general_free(input);
		exit(-1);
	}
}

void	ft_close(int pipe, t_input *input)
{
	if (close(pipe) == -1)
	{
		perror("");
		ft_general_free(input);
		exit(-1);
	}
}

void	ft_execve(char *path, char **cmd, t_input *input)
{
	if (execve(path, cmd, NULL) == -1)
	{
		perror("");
		ft_general_free(input);
		exit(-1);
	}
}

void	ft_check_pid(int pid, t_input *input)
{
	if (pid == -1)
	{
		perror("");
		ft_general_free(input);
		exit(-1);
	}
}
