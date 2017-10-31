/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:50:49 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:50:50 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_str(char *str, size_t n)
{
	char	*tmp;

	if (str)
	{
		tmp = ft_strdup(str);
		str = (char *)malloc(sizeof(char) * n + 1);
		free(str);
		str = NULL;
		str = (char *)malloc(sizeof(char) * n + 1);
		str = ft_strcpy(str, tmp);
		free(tmp);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * n + 1);
	}
	return (str);
}
