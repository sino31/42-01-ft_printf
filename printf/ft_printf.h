/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:04:39 by ashigema          #+#    #+#             */
/*   Updated: 2023/11/04 12:30:09 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);

size_t	put_char(int c);
size_t	put_str(char *s);
size_t	put_nbr(int n);
size_t	put_convert_base(size_t un, char *base);

size_t	identify_format(char format, va_list ap);
int		ft_printf(const char *argv1, ...);

#endif