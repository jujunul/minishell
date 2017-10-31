/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:55:47 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:55:48 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	index;

	index = 0;
	while (s2 && index < n && s2[index] != '\0')
	{
		s1[index] = s2[index];
		index++;
	}
	while (index < n)
	{
		s1[index] = '\0';
		index++;
	}
	s1[index] = '\0';
	return (s1);
}
