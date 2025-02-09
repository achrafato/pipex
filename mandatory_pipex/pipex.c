/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:44:57 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/03 17:20:58 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int fd[3], char *argv[], char *envp[], char *paths[])
{
	close(fd[0]);
	if (fd[2] == 2)
		(dup2(fd[1], STDOUT_FILENO), close(fd[1]));
	execute(paths, argv[fd[2]], envp);
}

void	parent(int fd[3], int out)
{
	close(fd[1]);
	(dup2(fd[0], STDIN_FILENO), close(fd[0]));
	dup2(out, STDOUT_FILENO);
}

void	verify_pipe_fork(int fd[3], int *pid)
{
	if (pipe(fd) == -1)
		(ft_printf("Error: %s\n", strerror(errno)), exit(EXIT_FAILURE));
	*pid = fork();
	if (*pid == -1)
		(ft_printf("Error: %s\n", strerror(errno)), exit(EXIT_FAILURE));
}

void	execute_commands(char *argv[], int argc, char *envp[], int my_files[2])
{
	int		fd[3];
	char	**paths;
	int		pid;
	int		a;

	a = 2;
	paths = handle_paths(envp);
	if (!paths)
		(perror("Error: invalid path"), exit(EXIT_FAILURE));
	dup2(my_files[0], STDIN_FILENO);
	while (a < argc - 1)
	{
		verify_pipe_fork(fd, &pid);
		if (pid == 0)
			fd[2] = a;
		if (pid == 0)
			child(fd, argv, envp, paths);
		else
			parent(fd, my_files[1]);
		a++;
	}
	a = 1;
	while (++a < argc - 1)
		wait(NULL);
	free_mem(paths, NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	my_files[2];

	if (argc == 5)
	{
		my_files[0] = open(argv[1], O_RDONLY);
		my_files[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (my_files[0] == -1 || my_files[1] == -1)
			(ft_printf("Error: %s\n", strerror(errno)), exit(EXIT_FAILURE));
		execute_commands(argv, argc, envp, my_files);
	}
	else
		(ft_printf("Error: invalid arguments\n"), exit(EXIT_FAILURE));
}
