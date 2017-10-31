/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:56:33 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:56:34 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strrchr(const char *s, int c)
{
	char		*str;

	str = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			str = (char *)s;
		s++;
	}
	if (c == '\0')
		str = (char *)s;
	return (str);
}
