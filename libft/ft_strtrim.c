/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:58:10 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:58:11 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cut_al(char a)
{
	if (a == ' ' || a == '\n' || a == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(const char *s)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (ft_cut_al(s[i]) == 1 && i < j)
		i++;
	while (ft_cut_al(s[j - 1]) == 1 && j != 0)
		j--;
	if (j > i)
		str = ft_strsub(s, i, j - i);
	else
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}
