/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:27:19 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/02 11:56:24 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

#include "../libft/libft.h"

int ft_print(const char* format, ...);

int ft_print_char(char c);
int ft_print_str(char *s);
int ft_print_unsigned(int nb);
int ft_print_nbr(int nb);

#endif
