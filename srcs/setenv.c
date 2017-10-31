/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:43:35 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:43:37 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		do_env(t_env *env, char **av)
{
	t_env	env2;

	if (av[1] == NULL)
		ft_draw_tab(env->env);
	else if (av[2] == NULL)
	{
		env2.env = set_environ(env->env);
		env2.c_env = set_environ(env->env);
		exec_shell(&env2, av[1], &(av[1]));
		ft_free_tab(env2.env);
		ft_free_tab(env2.c_env);
	}
	else
	{
		ft_putendl(av[1]);
		ft_error(3, NULL);
	}
	return (1);
}

void	change_one_env(t_env *env, char **av)
{
	char	*del;
	char	*new;
	int		len1;
	int		len2;

	del = env->env[get_nblenv(env->env, av[1])];
	len1 = ft_strlen(av[1]);
	if (av[2] == NULL)
	{
		new = (char *)malloc(sizeof(char) * (len1 + 2));
		new[len1 + 1] = 0;
	}
	else
	{
		len2 = ft_strlen(av[2]);
		new = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
		new[len1 + len2 + 1] = 0;
		ft_strncpy(new + len1 + 2, av[2], len2);
	}
	ft_strncpy(new, av[1], len1);
	new[len1] = '=';
	env->env[get_nblenv(env->env, av[1])] = new;
	free(del);
}

char	*addone_env(char **av)
{
	char	*str;
	int		len1;
	int		len2;

	len1 = ft_strlen(av[1]);
	if (av[2] != NULL)
		len2 = ft_strlen(av[2]);
	else
		len2 = 0;
	str = (char *)malloc(sizeof(char) * (len1 + 2));
	str = ft_strncpy(str, av[1], len1);
	str[len1] = '=';
	if (av[2] == NULL)
		str[len1 + 1] = 0;
	else
	{
		ft_strncpy(str + len1 + 1, av[2], len2);
		str[len1 + len2 + 2] = 0;
	}
	return (str);
}

void	setanenv(t_env *env, char **av)
{
	char	**nenv;
	char	**del;
	int		i;

	if (get_nblenv(env->env, av[1]) == -1)
	{
		i = 0;
		del = env->env;
		while (del[i] != NULL)
			i++;
		nenv = (char **)malloc(sizeof(char *) * (i + 2));
		i = 0;
		while (del[i] != NULL)
		{
			nenv[i] = ft_strdup(del[i]);
			i++;
		}
		nenv[i] = addone_env(av);
		nenv[i + 1] = NULL;
		env->env = nenv;
		ft_free_tab(del);
	}
	else
		change_one_env(env, av);
}

int		do_setenv(t_env *env, char **av)
{
	if (av[1] == NULL)
		ft_error(6, NULL);
	else if (av[2] == NULL || av[3] == NULL)
		setanenv(env, av);
	else
		ft_error(6, NULL);
	return (1);
}
