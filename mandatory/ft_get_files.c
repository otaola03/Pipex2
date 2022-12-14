/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:15:53 by jperez            #+#    #+#             */
/*   Updated: 2022/11/18 20:30:57 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

t_input	*ft_get_files(int argc, char **argv, int start)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	input->outfile = ft_strdup(*(argv + argc - 1));
	input->infile = ft_strdup(*(argv + start));
	if (access(input->infile, F_OK | R_OK))
	{
		perror("");
		free(input->infile);
		free(input->outfile);
		free(input);
		exit(-1);
	}
	return (input);
}
