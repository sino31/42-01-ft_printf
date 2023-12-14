/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:35:37 by ashigema          #+#    #+#             */
/*   Updated: 2023/11/03 16:40:38 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	identify_format(char format, va_list ap)
{
	if (format == 'c')
		return (put_char(va_arg(ap, int)));
	else if (format == 's')
		return (put_str(va_arg(ap, char *)));
	else if (format == 'p')
	{
		write(1, "0x", 2);
		return (put_convert_base((size_t)va_arg(ap, void *), "0123456789abcdef")
			+ 2);
	}
	else if (format == 'd' || format == 'i')
		return (put_nbr(va_arg(ap, int)));
	else if (format == 'u')
		return (put_convert_base((size_t)va_arg(ap, unsigned int),
				"0123456789"));
	else if (format == 'x')
		return (put_convert_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (put_convert_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		write(1, "%", 1);
	return (1);
}

int	ft_printf(const char *argv1, ...)
{
	va_list	ap;
	size_t	total;

	total = 0;
	va_start(ap, argv1);
	while (*argv1)
	{
		if (*argv1 != '%')
		{
			write(1, argv1, 1);
			total++;
		}
		else
		{
			argv1++;
			if (!(*argv1))
				break ;
			total += identify_format(*(char *)argv1, ap);
		}
		argv1++;
	}
	va_end(ap);
	return ((int)total);
}
