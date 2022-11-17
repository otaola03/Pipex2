/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:40:42 by jperez            #+#    #+#             */
/*   Updated: 2022/11/07 18:30:08 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_input	*input;
	int doc_on;

	if (argc >= 5)
	{
		doc_on = 0;
		if (ft_strncmp("here_doc", *(argv + 1), 8) == 0)
		{
			if (argc != 6)
				return (0);
			++argv;
			--argc;
			input = ft_get_files(--argc, ++argv, 1);
			doc_on++;
			env++;
		}
		else
			input = ft_get_files(--argc, ++argv, 0);
		ft_get_cmd(argc, argv, env, input);
		ft_pipex(argc, input, doc_on);
		ft_general_free(input);
	}
}
