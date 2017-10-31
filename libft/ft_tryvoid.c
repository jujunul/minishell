/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tryvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:59:01 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:59:02 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_tv(void *ret, void *err, char *where)
{
	if (ret == err)
		ft_die(error(1, strerror(errno)), where);
	return (ret);
}
