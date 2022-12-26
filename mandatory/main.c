/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:40:42 by jperez            #+#    #+#             */
/*   Updated: 2022/12/26 16:53:09 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_input	*input;

	if (argc == 5 && !ft_check_argv(argc, argv))
	{
		input = ft_get_files(--argc, ++argv, 0);
		ft_get_cmd(argc, argv, env, input);
		ft_pipex(argc, input);
		ft_general_free(input);
	}
}
