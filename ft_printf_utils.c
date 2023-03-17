/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryayla <ryayla@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:19:39 by ryayla            #+#    #+#             */
/*   Updated: 2023/01/04 12:20:08 by ryayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	return (write(1, str, len));
}

size_t	ft_print_nbr(long int n)
{
	size_t	sign;
	size_t	len;

	sign = 1;
	len = 0;
	if (n < 0)
	{
		len += ft_print_char('-');
		sign = -1;
	}
	n *= sign;
	if (n < 10)
		len += ft_print_char(n + 48);
	else
	{
		len += ft_print_nbr(n / 10);
		len += ft_print_nbr(n % 10);
	}
	return (len);
}

size_t	ft_print_nbr_base(unsigned long int n, const char *base)
{
	size_t	base_len;
	size_t	len;

	if (!base || ft_strlen(base) < 2)
		return (0);
	base_len = ft_strlen(base);
	len = 0;
	if (n < base_len)
		len += ft_print_char(base[n]);
	else
	{
		len += ft_print_nbr_base(n / base_len, base);
		len += ft_print_nbr_base(n % base_len, base);
	}
	return (len);
}
