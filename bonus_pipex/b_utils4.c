/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:17:14 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/04 10:59:43 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((s1[i] != s2[i]) || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		fd[2];
	char	*str;
	int		b_ool;

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		write(1, "heredoc> ", 9);
		str = get_next_line(0);
		while (str)
		{
			b_ool = str_len(str) - 1 == str_len(limiter);
			if (ft_strncmp(str, limiter, str_len(limiter)) == 0 && b_ool)
				exit(EXIT_SUCCESS);
			write(1, "heredoc> ", 10);
			write(fd[1], str, str_len(str));
			str = get_next_line(0);
		}
	}
	else
		(close(fd[1]), dup2(fd[0], STDIN_FILENO), wait(NULL));
}

////////////filter_cmd_from_spaces///////////////////

void	trim_space(char **cmd_prop)
{
	int		i;
	char	*to_free;

	i = 0;
	while (cmd_prop[i])
	{
		to_free = cmd_prop[i];
		cmd_prop[i] = ft_strtrim(cmd_prop[i], " ");
		free(to_free);
		i++;
	}
}

char	**filter_command(char *cmd1)
{
	char	**cmd_prop;

	cmd_prop = NULL;
	if (contains_char(cmd1, 39) || contains_char(cmd1, 34))
	{
		if (contains_char(cmd1, 39))
			cmd_prop = ft_split(cmd1, 39);
		else if (contains_char(cmd1, 34))
			cmd_prop = ft_split(cmd1, 34);
		trim_space(cmd_prop);
	}
	else
		cmd_prop = ft_split(cmd1, ' ');
	return (cmd_prop);
}
///////////////////////////////////////////////////