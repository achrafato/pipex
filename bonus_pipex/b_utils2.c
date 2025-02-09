/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:55:22 by aibn-che          #+#    #+#             */
/*   Updated: 2023/12/31 20:59:46 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	str_chr(char *s)
{
	int		i;
	int		j;
	char	*path;

	path = "PATH=";
	i = 0;
	while (s[i])
	{
		j = 0;
		while (path[j] && (path[j] == s[i + j]))
			j++;
		if (j == 5)
			return (1);
		i++;
	}
	return (0);
}

char	*substr(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (s + i + 1);
}

char	*mingle_path(char *path, char *file)
{
	char	*file_path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	file_path = malloc(sizeof(char) * (str_len(path) + str_len(file) + 1));
	if (!file_path)
		return (NULL);
	while (path && path[i])
	{
		file_path[i] = path[i];
		i++;
	}
	while (file && file[j])
	{
		file_path[i + j] = file[j];
		j++;
	}
	file_path[i + j] = '\0';
	return (file_path);
}

char	*append_char_front(char *file_name, char c)
{
	int		i;
	int		len;
	char	*res;

	len = str_len(file_name);
	res = malloc(sizeof(char) * (len + 2));
	if (!res)
		return (NULL);
	res[0] = c;
	i = 0;
	while (file_name && file_name[i])
	{
		res[i + 1] = file_name[i];
		i++;
	}
	res[i + 1] = '\0';
	return (res);
}

char	**handle_paths(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (str_chr(envp[i]))
			break ;
		i++;
	}
	path = substr(envp[i]);
	return (ft_split(path, ':'));
}
