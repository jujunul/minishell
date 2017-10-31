/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char_befor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:41:07 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:41:08 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_count_char_befor(char *str, char c)
{
	size_t		i;

	i = 0;
	while (str != NULL && str[i] != c && str[i] != '\0')
		i++;
	return (i);
}
