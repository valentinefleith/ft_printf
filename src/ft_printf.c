/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:54:08 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/02 11:03:14 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_print_arg(char format, va_list arguments);

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		count;

	if (!format)
		return (0);
	va_start(arguments, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_print_arg(*format, arguments);
		}
		else
			count += ft_print_char(*format);
		format++;
	}
	va_end(arguments);
	return (count);
}

int ft_print_arg(char format, va_list arguments)
{
	if (format == 'c')
		return ft_print_char(va_arg(arguments, int));
	if (format == '%')
		return ft_print_char('%');
	if (format == 's')
		return ft_print_str(va_arg(arguments, char *));
	if (format == 'd' || format == 'i')
		return ft_print_str(ft_itoa(va_arg(arguments, int)));
	return 0;
		
}

#include <stdio.h>
int	main(void)
{
	int ret_val = ft_printf("Hello %i\n", 14);
	printf("%i\n", ret_val);
}
