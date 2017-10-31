/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:42:09 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:42:12 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	move_from_home(t_env *env, char *way)
{
	char	*home;
	char	*new;
	int		len1;
	int		len2;

	if ((home = get_lenv(env->env, "HOME=")) == NULL)
		home = get_lenv(env->c_env, "HOME=");
	len1 = ft_strlen(home);
	len2 = ft_strlen(way);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	new = ft_strcpy(new, home);
	if (way[0] != '\0')
		ft_strcpy(new + len1, way);
	move_dir(env, new);
	free(new);
	free(home);
}

void	move_back(t_env *env)
{
	char	*oldpwd;

	if ((oldpwd = get_lenv(env->env, "OLDPWD=")) == NULL)
		oldpwd = get_lenv(env->c_env, "OLDPWD=");
	move_dir(env, oldpwd);
	free(oldpwd);
}

void	usual_cd(t_env *env, char *av)
{
	char	**ways;
	int		i;

	i = -1;
	if (av[0] == '-' && av[1] == 0)
		move_back(env);
	else if (av[0] == '~' && (av[1] == '/' || av[1] == 0))
		move_from_home(env, av + 1);
	else if (av[0] == '/')
		move_dir(env, av);
	else
	{
		ways = ft_strsplit(av, '/');
		while (ways[++i] != NULL)
		{
			if (ft_strcmp(ways[i], "..") == 0 && ft_strcmp(ways[i], ".") != 0)
			{
				if (rm_one_dir(env) == -1)
					break ;
			}
			else if (ft_strcmp(ways[i], ".") != 0)
				if (add_one_dir(env, ways[i]) == -1)
					break ;
		}
		ft_free_tab(ways);
	}
}

void	dual_cd(t_env *env, char **av)
{
	char	*pwd;
	char	*tmp;
	char	*new;
	int		len1;
	int		len2;

	if ((pwd = get_lenv(env->env, "PWD=")) == NULL)
		pwd = get_lenv(env->c_env, "PWD=");
	if ((tmp = ft_strstr(pwd, av[1])) == NULL)
		ft_error(10, av[1]);
	else
	{
		len1 = ft_strlen(pwd);
		len2 = ft_count_char_befor(tmp, '/');
		new = (char *)malloc(sizeof(char) * (len1 - len2 + ft_strlen(av[2]) + 1));
		new = ft_strncpy(new, pwd, len1 - ft_strlen(tmp));
		len2 += ft_strlen(new);
		ft_strcpy(new + len1 - ft_strlen(tmp), av[2]);
		len1 = ft_strlen(new);
		new[len1] = '/';
		ft_strcpy(new + len1 + 1, pwd + len2 + 1);
		move_dir(env, new);
		free(new);
	}
	free(pwd);
}

int		do_cd(t_env *env, char **av)
{
	char	*path;

	if (av[1] == NULL)
	{
		if ((path = get_lenv(env->env, "HOME=")) == NULL)
			path = get_lenv(env->c_env, "HOME=");
		move_dir(env, path);
	}
	else if (av[2] == NULL)
		usual_cd(env, av[1]);
	else if (av[3] == NULL)
		dual_cd(env, av);
	else
		ft_error(1, "cd");
	return (1);
}
