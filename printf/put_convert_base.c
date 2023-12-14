/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_convert_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:39:53 by ashigema          #+#    #+#             */
/*   Updated: 2023/09/30 17:02:45 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rec_convert(size_t un, size_t base_size, char *base, size_t *cnt)
{
	if (un > 0)
	{
		rec_convert(un / base_size, base_size, base, cnt);
		write(1, &base[un % base_size], 1);
		(*cnt)++;
	}
}

size_t	put_convert_base(size_t un, char *base)
{
	size_t		base_size;
	size_t		cnt;

	cnt = 0;
	if (un == 0)
	{
		write(1, "0", 1);
		cnt++;
		return (cnt);
	}
	base_size = ft_strlen(base);
	rec_convert(un, base_size, base, &cnt);
	return (cnt);
}
