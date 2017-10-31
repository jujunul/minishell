/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:47:28 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:47:29 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*s;
	char	*a;
	char	*b;

	s = (char *)malloc(sizeof(char) * n);
	a = s1;
	b = (char *)s2;
	ft_memcpy(s, b, n);
	ft_memcpy(a, s, n);
	free(s);
	return (s1);
}
