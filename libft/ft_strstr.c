/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:57:22 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:57:22 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	len1;
	unsigned int	lentmp;
	int				len2;

	len1 = 0;
	len2 = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (len1 < ft_strlen(s1) + 1)
	{
		if (s2[len2] == '\0')
			return ((char *)s1 + (len1 - len2));
		else if (s1[len1] == s2[len2])
		{
			if (len2++ == 0)
				lentmp = (len1 + 1);
		}
		else
		{
			len2 = 0;
			len1 = lentmp++;
		}
		len1++;
	}
	return (NULL);
}
