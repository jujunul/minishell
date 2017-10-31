/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:40:36 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:40:45 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addpath(char *path, char *file)
{
	char	*str;
	int		len1;
	int		len2;

	len1 = ft_strlen(path);
	if (path[len1 - 1] != '/')
		len1++;
	len2 = ft_strlen(file);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	ft_strcpy(str, path);
	if (path[len1 - 1] != '/')
	{
		str[len1 - 1] = '/';
	}
	ft_strcpy(str + len1, file);
	str[len1 + len2] = 0;
	return (str);
}
