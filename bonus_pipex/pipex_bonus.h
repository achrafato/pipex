/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:56:00 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/03 12:29:53 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include "../ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

char	**ft_split(char const *s, char c);

int		str_chr(char *s);
char	*substr(char *s);
char	*mingle_path(char *path, char *file);
char	*append_char_front(char *file_name, char c);
char	**handle_paths(char **envp);

void	free_mem(char **arr, char *mem1);
int		str_len(char *str);
void	here_doc(char *limiter);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	**filter_command(char *cmd1);

char	*ft_strtrim(char *s1, char *set);

int		contains_char(char *s, char c);

#endif