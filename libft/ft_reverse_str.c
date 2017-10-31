/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:51:00 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:51:00 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_str(char *str)
{
	size_t	i;
	size_t	j;
	char	*reverse;

	i = 0;
	j = ft_strlen(str) - 1;
	reverse = (char *)malloc(sizeof(char) * (j + 2));
	while (i < ft_strlen(str))
	{
		reverse[i] = str[j];
		i++;
		j--;
	}
	reverse[i] = '\0';
	free(str);
	return (reverse);
}
