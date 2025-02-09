/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:34:47 by aibn-che          #+#    #+#             */
/*   Updated: 2023/11/18 14:38:28 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

///////print_x////////////

static void	print_hex(unsigned int nb, int *printed_chars, char specifier)
{
	if (nb / 16)
		print_hex(nb / 16, printed_chars, specifier);
	if (nb % 16 >= 10)
	{
		if (specifier == 'x')
			put_cha('a' + ((nb % 16) % 10), printed_chars);
		else
			put_cha('A' + ((nb % 16) % 10), printed_chars);
	}
	else
		put_cha(nb % 16 + '0', printed_chars);
}

void	print_x(va_list args, int *printed_chars, char specifier)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	print_hex(nb, printed_chars, specifier);
}
///////print_x////////////

static void	print_hex_p(unsigned long nb, int *printed_chars)
{
	if (nb / 16)
		print_hex_p(nb / 16, printed_chars);
	if (nb % 16 >= 10)
		put_cha('a' + ((nb % 16) % 10), printed_chars);
	else
		put_cha(nb % 16 + '0', printed_chars);
}

void	print_p(va_list args, int *ptr, __attribute__((unused)) char sp)
{
	unsigned long long	nb;

	nb = (unsigned long long)va_arg(args, void *);
	write(1, "0x", 2);
	(*ptr) += 2;
	print_hex_p(nb, ptr);
}
