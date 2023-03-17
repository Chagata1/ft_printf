/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryayla <ryayla@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:16:30 by ryayla            #+#    #+#             */
/*   Updated: 2023/01/04 12:28:09 by ryayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_convert(char type, va_list ap);
size_t	ft_print_nbr(long int n);
size_t	ft_print_nbr_base(unsigned long int n, const char *base);
size_t	ft_strlen(const char *s);

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);

#endif
