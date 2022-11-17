/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:40:42 by jperez            #+#    #+#             */
/*   Updated: 2022/11/07 19:13:08 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_input	*input;

	if (argc == 5)
	{
		input = ft_get_files(--argc, ++argv, 0);
		ft_get_cmd(argc, argv, env, input);
		ft_pipex(argc, input);
		ft_general_free(input);
	}
}
