/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:33:49 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/02 20:41:29 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	while (*envp && envp[i])
	{
		if (str_chr(envp[i]))
			break ;
		i++;
	}
	if (!*envp)
		return (NULL);
	path = substr(envp[i]);
	return (ft_split(path, ':'));
}

void	free_mem(char **arr, char *mem1)
{
	int	i;

	i = 0;
	free(mem1);
	while (arr && arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
}
