/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:55:25 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:55:26 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	index;
	int				len;

	index = 0;
	len = ft_strlen(s1);
	while (index < n && s2[index] != '\0')
	{
		s1[len] = s2[index];
		len++;
		index++;
	}
	s1[len] = '\0';
	return (s1);
}
