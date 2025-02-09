/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:56:14 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/03 11:14:08 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include "../ft_printf/ft_printf.h"

char	*substr(char *s);
char	*mingle_path(char *path, char *file);
char	*append_char_front(char *file_name, char c);
char	**handle_paths(char **envp);
void	free_mem(char **arr, char *mem1);

char	**ft_split(char const *s, char c);

int		str_chr(char *s);
char	*ft_strtrim(char *s1, char *set);

int		str_len(char *str);
int		contains_char(char *s, char c);

void	execute(char **paths, char *cmd1, char *envp[]);

#endif