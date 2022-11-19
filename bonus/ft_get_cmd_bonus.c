/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:02:26 by jperez            #+#    #+#             */
/*   Updated: 2022/11/19 19:55:36 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

char	*ft_check_path_acces(char *cmd, char **env_path)
{
	int		i;
	char	*path;
	char	*aux_cmd;

	i = 0;
	aux_cmd = ft_strjoin("/", cmd);
	while (env_path[i])
	{
		path = ft_strjoin(env_path[i], aux_cmd);
		if (!access(path, F_OK))
			break ;
		else
		{
			free(path);
			path = NULL;
		}
		i++;
	}
	free(aux_cmd);
	if (!path)
		return (ft_strdup("INVALID"));
	return (path);
}

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	**env_path;
	char	*path;

	i = 0;
	while (env[i])
		if (!ft_strncmp("PATH", env[i++], 4))
			break ;
	if (ft_strncmp("PATH", env[i - 1], 4))
		return (NULL);
	env_path = (char **)malloc(sizeof(char *) * \
		(ft_count_words_2(env[i - 1], ':') + 1));
	if (!env_path)
		return (NULL);
	env_path = ft_split_2(env_path, env[i - 1] + 5, ':');
	path = ft_check_path_acces(cmd, env_path);
	ft_free_2d_arr(env_path);
	return (path);
}

void	ft_get_cmd(int argc, char **argv, char **env, t_input *input)
{
	int		i;

	input->cmd = (char ***)malloc(sizeof(char **) * ((argc - 2) + 1));
	i = 0;
	while (i < argc - 2)
	{
		input->cmd[i] = (char **)malloc(sizeof(char *) * \
			(ft_count_words(argv[i + 1]) + 2));
		if (!input->cmd[i])
			return ;
		ft_split(input->cmd[i], argv[i + 1]);
		input->cmd[i][0] = ft_get_path(input->cmd[i][1], env);
		i++;
	}
	input->cmd[i] = NULL;
}
