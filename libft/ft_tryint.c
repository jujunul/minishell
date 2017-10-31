/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tryint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:58:52 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:58:53 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_ti(int ret, int err, char *where)
{
	if (ret == err)
		ft_die(error(ret, strerror(errno)), where);
	return (ret);
}
