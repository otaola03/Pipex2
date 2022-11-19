/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:54:19 by jperez            #+#    #+#             */
/*   Updated: 2022/11/19 19:54:48 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# define PIPEX_BONUS_H

# include<fcntl.h>
# include<unistd.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

# define READ 0
# define WRITE 1

typedef struct s_input
{
	char	***cmd;
	char	*infile;
	char	*outfile;
	char	*delimiter;
	char	**path;
	int		**pipes;
	int		*pid;
}	t_input;

/*------- AUX -------*/

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);

/*------- GET-FILES -------*/

t_input	*ft_get_files(int argc, char **argv, int start);

/*------- GET-CMD -------*/

void	ft_get_cmd(int argc, char **argv, char **env, t_input *input);

/*------- SPLIT -------*/
char	**ft_split(char **matrix, char *str);
int		ft_count_words(char *s);
int		ft_count_words_2(char *s, char c);
char	**ft_split_2(char **matrix, char *str, char c);

/*------- GENERAL-FREE -------*/
void	ft_free_cmd(char ***cmd);
void	ft_free_files(t_input *files);
void	ft_general_free(t_input *input);
void	ft_free_2d_arr(char **arr);

/*------- FUNCTIONS -------*/

void	ft_pipe(int *fd, t_input *input);
void	ft_dup2(int fd1, int fd2, t_input *input);
void	ft_close(int pipe, t_input *input);
void	ft_execve(char *path, char **cmd, t_input *input);
void	ft_check_pid(int pid, t_input *input);

/*------- PIPEX -------*/

void	ft_pipex(int argc, t_input *input, int doc_on);

/*------- MANAGE-FILES -------*/

void	ft_keep_file_in_pipe(t_input *input);
void	ft_keep_pipe_in_file(t_input *input, int doc_on);

/*------- HERE-DOC -------*/

void	ft_here_doc(t_input *input);

/*------- GET-NEXT-LINE -------*/
char	*get_next_line(int fd);

#endif
