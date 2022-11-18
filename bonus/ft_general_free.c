/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:15 by jperez            #+#    #+#             */
/*   Updated: 2022/11/18 20:35:13 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_free_cmd(char ***cmd)
{
	int	i;
	int	j;

	i = -1;
	while (cmd[++i])
	{
		j = -1;
		while (cmd[i][++j])
			free(cmd[i][j]);
		free(cmd[i][j]);
		free(cmd[i]);
	}
	free(cmd);
}

void	ft_free_2d_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	ft_free_childs(t_input *input)
{
	int	i;

	i = 0;
	while (input->pipes[i])
	{
		free(input->pipes[i]);
		i++;
	}
	free(input->pipes);
	free(input->pid);
}

void	ft_free_files(t_input *input)
{
	free(input->infile);
	free(input->outfile);
	free(input->delimiter);
}

void	ft_general_free(t_input *input)
{
	ft_free_files(input);
	ft_free_childs(input);
	ft_free_cmd(input->cmd);
	free(input);
	exit(-1);
}
