/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:19:51 by jperez            #+#    #+#             */
/*   Updated: 2022/11/19 19:56:46 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

void	ft_child_process(int i, int argc, t_input *input, int doc_on)
{
	int	j;

	j = 0;
	while (j < argc - 1)
	{
		if (j != i)
			ft_close(input->pipes[j][READ], input);
		if (j != i + 1)
			ft_close(input->pipes[j][WRITE], input);
		j++;
	}
	ft_dup2(input->pipes[i][READ], STDIN_FILENO, input);
	if (i != argc - 3)
		ft_dup2(input->pipes[i + 1][WRITE], STDOUT_FILENO, input);
	else
		ft_keep_pipe_in_file(input, doc_on);
	ft_execve(input->cmd[i][0], &input->cmd[i][1], input);
	ft_close(input->pipes[i][READ], input);
	ft_close(input->pipes[i + 1][WRITE], input);
	exit(-1);
}

void	ft_create_pipes(int argc, t_input *input)
{
	int	i;

	input->pipes = (int **)malloc(sizeof(char *) * (argc - 1 + 1));
	i = 0;
	while (i < argc - 1)
	{
		input->pipes[i] = (int *)malloc(sizeof(int) * 2);
		ft_pipe(input->pipes[i], input);
		i++;
	}
	input->pipes[i] = NULL;
	input->pid = (int *)malloc(sizeof(int) * (argc - 2));
}

void	ft_pipex(int argc, t_input *input, int doc_on)
{
	int	i;

	ft_create_pipes(argc, input);
	if (doc_on == 1)
		ft_here_doc(input);
	else
		ft_keep_file_in_pipe(input);
	i = 0;
	while (i < argc - 2)
	{
		input->pid[i] = fork();
		ft_check_pid(input->pid[i], input);
		if (input->pid[i] == 0)
			ft_child_process(i, argc, input, doc_on);
		i++;
	}
}
