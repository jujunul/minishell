/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:46:06 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:46:07 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * n);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, n);
	return (s);
}
