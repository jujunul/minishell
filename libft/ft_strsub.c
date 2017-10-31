/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:57:57 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:57:58 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;

	i = 0;
	new = NULL;
	if (s)
	{
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (new == NULL)
			return (NULL);
		while (len != 0 && s[start] != '\0')
		{
			new[i] = s[start];
			start++;
			i++;
			len--;
		}
		new[i] = '\0';
	}
	return (new);
}
