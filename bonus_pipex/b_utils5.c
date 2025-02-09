/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:20:33 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/01 22:14:14 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

///////////////////trim///////////////////////
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = str_len((char *)s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	fill_in(char *trim, int start, int end, char const *s1)
{
	int	i;

	i = 0;
	while (start <= end && s1[start])
		trim[i++] = s1[start++];
	trim[i] = '\0';
}

char	*ft_strtrim(char *s1, char *set)
{
	int		len;
	int		start;
	int		end;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	len = str_len(s1);
	end = len - 1;
	start = 0;
	while (start < len && ft_strchr(set, s1[start]))
		start++;
	if (start >= len)
		return (ft_strdup("\0"));
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	trim = (char *)malloc((end - start + 1) + 1);
	if (!trim)
		return (NULL);
	fill_in(trim, start, end, s1);
	return (trim);
}

///////////////////trim///////////////////////
int	contains_char(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
