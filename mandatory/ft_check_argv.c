/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:16:37 by jperez            #+#    #+#             */
/*   Updated: 2022/12/21 17:22:14 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	ft_check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (ft_strlen(argv[i]) == 0)
			return (1);
	return (0);
}
