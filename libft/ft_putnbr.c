/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:49:39 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:49:41 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(int n)
{
	long	div;
	int		index;
	long	nb;

	nb = (long)n;
	index = 0;
	div = 1;
	if (nb < 0)
	{
		index = ft_putchar('-');
		nb = nb * -1;
	}
	while ((nb / div) >= 10)
		div = div * 10;
	while (div > 0)
	{
		index += ft_putchar((nb / div) % 10 + 48);
		div = div / 10;
	}
	return (index);
}
