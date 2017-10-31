/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:46:56 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:46:57 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int	index;
	char			*a;
	char			*b;

	a = s1;
	b = (char *)s2;
	index = 0;
	while (index < n)
	{
		a[index] = b[index];
		index++;
	}
	return (s1);
}
