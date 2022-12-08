/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:36:39 by jperez            #+#    #+#             */
/*   Updated: 2022/12/08 19:52:01 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

int	ft_count_words(char *s)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\0')
		cont++;
	while (s[i])
	{
		if (((s[i] == '\t' && s[i + 1] != '\t' ) || \
				(s[i] == '\n' && s[i + 1] != '\n') || \
				(s[i] == ' ' && s[i + 1] != ' ')) && s[i + 1] != '\0')
			cont++;
		i++;
	}
	return (cont);
}

char	**ft_split(char **matrix, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
			i++;
		j = i;
		while (str[j] != ' ' && str[j] != '\t' && str[j] != '\n' && str[j])
			j++;
		matrix[k] = (char *)malloc(sizeof(char) * (j - i + 1));
		if (!matrix[k])
			return (NULL);
		j = 0;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			matrix[k][j++] = str[i++];
		matrix[k][j] = '\0';
		k++;
	}
	matrix[k] = NULL;
	return (matrix);
}

int	ft_count_words_2(char *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	if (s[i] != c && s[i] != '\0')
		cont++;
	while (s[i])
	{
		if (((s[i] == c && s[i + 1] != c) \
			&& s[i + 1] != '\0'))
			cont++;
		i++;
	}
	return (cont);
}

char	**ft_split_2(char **matrix, char *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while ((str[i] == c && str[i]))
			i++;
		j = 0;
		while (str[i + j] != c && str[i + j])
			j++;
		matrix[k] = (char *)malloc(sizeof(char) * (j + 1));
		if (!matrix[k])
			return (NULL);
		j = 0;
		while (str[i] != c && str[i])
			matrix[k][j++] = str[i++];
		matrix[k][j] = '\0';
		k++;
	}
	matrix[k] = NULL;
	return (matrix);
}
