/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:46:41 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:46:45 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1a;
	unsigned char	*s2a;
	unsigned int	index;

	index = 0;
	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	while (index < n)
	{
		if (s1a[index] != s2a[index])
			return (s1a[index] - s2a[index]);
		index++;
	}
	return (0);
}
