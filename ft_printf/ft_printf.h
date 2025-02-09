/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:53:15 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/04 11:27:29 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

void	put_cha(char c, int *printed_chars);

void	print_s(va_list args, int *ptr, __attribute__((unused)) char sp);
void	print_c(va_list args, int *ptr, __attribute__((unused)) char sp);

void	print_x(va_list args, int *printed_chars, char specifier);
void	print_p(va_list args, int *ptr, __attribute__((unused)) char sp);

void	print_d(va_list args, int *ptr, __attribute__((unused)) char sp);

void	print_u(va_list args, int *printed_ch, __attribute__((unused)) char sp);

typedef struct specifiers_functions
{
	char	sp;
	void	(*print_sp)(va_list args, int *p, char c);
}	t_sp_fun;

#endif