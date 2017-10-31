/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:55:36 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:55:37 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0' && index < n)
	{
		if (s1[index] != s2[index])
			return ((char)s1[index] - (char)s2[index]);
		index++;
	}
	if (index < n && s2[index] == '\0')
		return ((char)s2[index] - (char)s1[index]);
	if (index < n && s1[index] == '\0')
		return ((char)s2[index] - (char)s1[index]);
	return (0);
}
