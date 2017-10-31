/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:45:19 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 18:45:20 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static void		ft_lstdelcontent(void *data, size_t size)
{
	if (data)
		free(data);
	(void)size;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*prev_item;
	t_list	*new_item;
	t_list	*first_elem;

	prev_item = NULL;
	first_elem = NULL;
	while (lst)
	{
		new_item = (t_list *)malloc(sizeof(t_list));
		if (!new_item)
		{
			if (first_elem)
				ft_lstdel(&first_elem, ft_lstdelcontent);
			return (NULL);
		}
		ft_memcpy(new_item, f(lst), sizeof(t_list));
		if (first_elem == NULL)
			first_elem = new_item;
		if (prev_item != NULL)
			prev_item->next = new_item;
		prev_item = new_item;
		lst = lst->next;
	}
	return (first_elem);
}
