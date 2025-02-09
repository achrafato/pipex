/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:44:57 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/04 10:59:18 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute(char **paths, char *cmd1, char *envp[])
{
	char	**cmd_prop;
	char	*full_path;
	char	*cmd_name;
	int		i;

	i = 0;
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

void	execute_in_child(char *argv[], char *envp[], int arr[3])
{
	char	**paths;
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		(ft_printf("Error: %s\n", strerror(errno)), exit(EXIT_FAILURE));
	paths = handle_paths(envp);
	pid = fork();
	if (pid == -1)
		(ft_printf("Error: %s\n", strerror(errno)), exit(EXIT_FAILURE));
	if (pid == 0)
	{
		close(fd[0]);
		if (arr[2] == arr[0] - 2)
			dup2(arr[1], STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
		execute(paths, argv[arr[2]], envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		free_mem(paths, NULL);
	}
}

void	execute_in_parent(char *argv[], char *envp[], int arr[3])
{
	char	**paths;

	paths = handle_paths(envp);
	execute(paths, argv[arr[2]], envp);
	free_mem(paths, NULL);
}

void	handle_commands(int argc, char *argv[], char *envp[], int my_files[2])
{
	int	k;
	int	arr[3];

	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		k = 3;
		here_doc(argv[2]);
	}
	else
	{
		k = 2;
		dup2(my_files[0], STDIN_FILENO);
		close(my_files[0]);
	}
	arr[0] = argc;
	arr[1] = my_files[1];
	while (k <= argc - 2)
	{
		arr[2] = k;
		execute_in_child(argv, envp, arr);
		k++;
	}
	k = 1;
	while (++k <= argc - 2)
		wait(NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	my_files[2];

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8))
		{
			my_files[0] = open(argv[1], O_RDONLY);
			if (my_files[0] < 0)
			{
				ft_printf("Error: %s\n", strerror(errno));
				exit(EXIT_FAILURE);
			}
		}
		my_files[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (my_files[1] < 0)
			(ft_printf("Error: %s\n", strerror(errno)), exit(EXIT_FAILURE));
		handle_commands(argc, argv, envp, my_files);
	}
	else
	{
		(ft_printf("Error: invalid arguments\n"), exit(EXIT_FAILURE));
	}
	return (0);
}
