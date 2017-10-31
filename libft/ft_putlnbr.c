/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:49:23 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:49:24 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putlnbr(long n)
{
	long	div;
	int		index;

	index = 0;
	div = 1;
	if (n < 0)
	{
		index = ft_putchar('-');
		n = n * -1;
	}
	while ((n / div) >= 10)
		div = div * 10;
	while (div > 0)
	{
		index += ft_putchar((n / div) % 10 + 48);
		div = div / 10;
	}
	return (index);
}
