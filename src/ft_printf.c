/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:54:08 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/02 10:34:03 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_print_arg(char format, va_list arguments);

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		count;
	int		fd;

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
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	va_end(arguments);
	return (count);
}

int ft_print_arg(char format, va_list arguments)
{
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(arguments, int), 1);
		return 1;
	}
	return 0;
		
}

int	main(void)
{
	ft_printf("Hello %c\n", 'a');
}
