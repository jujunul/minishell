/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:46:18 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:46:19 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	index;
	unsigned char	*a;
	unsigned char	*b;

	a = s1;
	b = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		a[index] = b[index];
		if (a[index] == (unsigned char)c)
			return (s1 + index + 1);
		index++;
	}
	return ((void *)0);
}
