/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:35:08 by aibn-che          #+#    #+#             */
/*   Updated: 2023/11/18 11:40:27 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_unsigned_int(unsigned int nb, int *printed_chars)
{
	if (nb / 10)
		print_unsigned_int(nb / 10, printed_chars);
	put_cha(nb % 10 + '0', printed_chars);
}

void	print_u(va_list args, int *ptr, __attribute__((unused)) char sp)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	print_unsigned_int(nb, ptr);
}
