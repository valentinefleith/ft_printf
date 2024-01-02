/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:37:54 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/02 11:53:24 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_print_str(char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return i;
}

int ft_print_unsigned(int nb)
{
	int count;

	count = 0;
	if (nb < 10)
		count += ft_print_char(nb + '0');
	else
	{
		count += ft_print_unsigned(nb / 10);
		count += ft_print_unsigned(nb % 10);
	}
	return (count);
}

int ft_print_nbr(int nb)
{
	int count;
	
	count = 0;
	if (nb < 0)
	{
		count += ft_print_char('-');
		nb *= -1;
	}
	return count + ft_print_unsigned(nb);
}

