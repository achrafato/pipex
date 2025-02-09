/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:50:33 by aibn-che          #+#    #+#             */
/*   Updated: 2023/11/18 13:54:31 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_sp_fun	*search_fn(char specifier)
{
	int			len_func;
	t_sp_fun	func[8];
	t_sp_fun	*myobj;

	func[0] = (t_sp_fun){'s', print_s};
	func[1] = (t_sp_fun){'c', print_c};
	func[2] = (t_sp_fun){'d', print_d};
	func[3] = (t_sp_fun){'i', print_d};
	func[4] = (t_sp_fun){'x', print_x};
	func[5] = (t_sp_fun){'X', print_x};
	func[6] = (t_sp_fun){'u', print_u};
	func[7] = (t_sp_fun){'p', print_p};
	len_func = sizeof(func) / sizeof(t_sp_fun);
	while (len_func--)
	{
		if (func[len_func].sp == specifier)
		{
			myobj = &func[len_func];
			return (myobj);
		}
	}
	return (NULL);
}

static void	handle_sp(char format, int *printed_chars, va_list args)
{
	t_sp_fun	*myfunc;

	myfunc = search_fn(format);
	if (myfunc)
		myfunc->print_sp(args, printed_chars, format);
	else if (format)
		put_cha(format, printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			printed_chars;

	if (write(1, "", 0) < 0)
		return (-1);
	i = 0;
	printed_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				i++;
				handle_sp(format[i], &printed_chars, args);
			}
		}
		else if (format[i])
			put_cha(format[i], &printed_chars);
		i++;
	}
	va_end(args);
	return (printed_chars);
}
