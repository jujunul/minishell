/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:50:25 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:50:27 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putstr(const char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
		index++;
	write(1, str, index);
	return (index);
}
