/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:34:58 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/04 11:28:03 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(va_list args, int *ptr, __attribute__((unused)) char sp)
{
	int		i;
	char	*s;

	i = 0;
	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	while (s[i])
	{
		write(2, &s[i++], 1);
		(*ptr)++;
	}
}

void	print_c(va_list args, int *ptr, __attribute__((unused)) char sp)
{
	int	a;

	a = va_arg(args, int);
	(*ptr)++;
	write(1, &a, 1);
}

void	put_cha(char c, int *printed_chars)
{
	if (printed_chars)
		(*printed_chars)++;
	write(2, &c, 1);
}
