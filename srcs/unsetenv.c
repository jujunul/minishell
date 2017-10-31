/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:43:09 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:43:11 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		do_unsetenv(t_env *env, char **av)
{
	char	**del;
	char	**new;
	int		i;
	int		j;
	int		nb;

	if (av[1] != NULL && av[2] == NULL)
	{
		if ((nb = get_nblenv(env->env, av[1])) != -1)
		{
			del = env->env;
			i = 0;
			while (del[i] != NULL)
				i++;
			new = (char **)malloc(sizeof(char *) * i);
			i = 0;
			j = 0;
			while (del[i] != NULL)
			{
				if (i != nb)
				{
					new[j] = ft_strdup(del[i]);
					j++;
				}
				i++;
			}
			new[j] = NULL;
			ft_free_tab(del);
			env->env = new;
		}
		else
			ft_error(8, av[1]);
	}
	else
		ft_error(7, NULL);
	return (1);
}
