/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:59:13 by ashigema          #+#    #+#             */
/*   Updated: 2023/09/30 16:58:18 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rec_nbr(long long nb, size_t *cnt)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		(*cnt)++;
		nb *= -1;
	}
	if (nb >= 10)
		rec_nbr(nb / 10, cnt);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	(*cnt)++;
}

size_t	put_nbr(int n)
{
	long long	nb;
	size_t		cnt;

	nb = (long long)n;
	cnt = 0;
	rec_nbr(nb, &cnt);
	return (cnt);
}
