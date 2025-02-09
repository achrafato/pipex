/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:52:20 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/03 17:20:01 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	execute(char **paths, char *cmd1, char *envp[])
{
	char	**cmd_prop;
	char	*full_path;
	char	*cmd_name;
	int		i;

	i = 0;
	cmd_prop = NULL;
	full_path = NULL;
	cmd1 = ft_strtrim(cmd1, " ");
	cmd_prop = filter_command(cmd1);
	cmd_name = append_char_front(cmd_prop[0], '/');
	while (paths[i])
	{
		free(full_path);
		full_path = mingle_path(paths[i], cmd_name);
		if (!access(cmd_prop[0], F_OK | X_OK))
			(free(full_path), full_path = cmd_prop[0]);
		if (access(full_path, F_OK | X_OK) != -1)
			break ;
		i++;
	}
	free_mem(paths, cmd_name);
	execve(full_path, cmd_prop, envp);
	free_mem(cmd_prop, full_path);
	(ft_printf("Error: %s\n", strerror(errno)), exit(EXIT_FAILURE));
}
