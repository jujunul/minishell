/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:53:01 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:53:02 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		index;

	index = 0;
	len = ft_strlen(s1);
	dup = (char*)malloc(sizeof(char) * len + 1);
	if (dup != NULL)
	{
		while (s1 && s1[index] != '\0')
		{
			dup[index] = s1[index];
			index++;
		}
		dup[index] = '\0';
	}
	return (dup);
}
