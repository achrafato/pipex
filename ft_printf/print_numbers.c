/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:35:04 by aibn-che          #+#    #+#             */
/*   Updated: 2023/11/18 11:06:48 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int a, int *printed_chars)
{
	int			sign;
	long int	n;

	n = (long int)a;
	sign = 1;
	if (n < 0)
	{
		n *= -1;
		sign = -1;
		put_cha('-', printed_chars);
	}
	if (n / 10)
		ft_putnbr(n / 10, printed_chars);
	put_cha((n % 10) + '0', printed_chars);
}

void	print_d(va_list args, int *ptr, __attribute__((unused)) char sp)
{
	int		nb;

	nb = va_arg(args, int);
	ft_putnbr(nb, ptr);
}
