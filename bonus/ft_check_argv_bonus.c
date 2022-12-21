/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:16:37 by jperez            #+#    #+#             */
/*   Updated: 2022/12/21 18:43:31 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

int	ft_check_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		return (1);
	}
	close(fd);
	return (1);
}

int	ft_check_argv(int argc, char **argv)
{
	int	i;
	int	error;

	error = 0;
	i = 1;
	if (ft_strncmp("here_doc", argv[i], 8) == 0)
		i += 1;
	if (i == 1 && ft_check_infile(argv[i]))
		error = 1;
	while (++i < argc)
	{
		if (i == argc - 1 && ft_strlen(argv[i]) == 0)
		{
			write(2, "zsh: no such file or directory:\n", 33);
			return (1);
		}
		else if (ft_strlen(argv[i]) == 0)
		{
			write(2, "zsh: permission denied:\n", 24);
			return (1);
		}
	}
	if (error)
		return (1);
	return (0);
}
