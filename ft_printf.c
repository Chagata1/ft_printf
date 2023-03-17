/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryayla <ryayla@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:06:10 by ryayla            #+#    #+#             */
/*   Updated: 2023/01/04 12:11:20 by ryayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert(char type, va_list ap)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_print_char(va_arg(ap, int));
	if (type == 's')
		len += ft_print_str(va_arg(ap, char *));
	if (type == 'p')
	{
		len += ft_print_str("0x")
			+ ft_print_nbr_base(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	if (type == 'd' || type == 'i')
		len += ft_print_nbr(va_arg(ap, int));
	if (type == 'u')
		len += ft_print_nbr_base(va_arg(ap, unsigned), "0123456789");
	if (type == 'x')
		len += ft_print_nbr_base(va_arg(ap, unsigned), "0123456789abcdef");
	if (type == 'X')
		len += ft_print_nbr_base(va_arg(ap, unsigned), "0123456789ABCDEF");
	if (type == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_convert(*(format + 1), ap);
			format++;
		}
		else
			len += ft_print_char(*format);
		format++;
	}
	va_end(ap);
	return (len);
}
