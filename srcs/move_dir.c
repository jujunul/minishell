/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:43:20 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:43:23 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	set_oldpwd(t_env *env)
{
	char	*oldpwd1;
	char	*newold1;
	char	*oldpwd2;
	char	*pwd;
	char	**av;

	oldpwd2 = env->c_env[get_nblenv(env->c_env, "OLDPWD=")];
	pwd = env->c_env[get_nblenv(env->c_env, "PWD=")];
	newold1 = (char *)malloc(sizeof(char) * (ft_strlen(pwd) + 4));
	newold1[0] = 'O';
	newold1[1] = 'L';
	newold1[2] = 'D';
	ft_strcpy(newold1 + 3, pwd);
	newold1[ft_strlen(pwd) + 3] = 0;
	env->c_env[get_nblenv(env->c_env, "OLDPWD=")] = ft_strdup(newold1);
	if (get_nblenv(env->env, "OLDPWD=") == -1)
	{
		av = (char **)malloc(sizeof(char *) * 4);
		av[0] = ft_strdup("setenv");
		av[1] = ft_strdup("OLDPWD");
		av[2] = ft_strdup(env->c_env[get_nblenv(env->c_env, "PWD=")]);
		av[3] = NULL;
		setanenv(env, av);
		ft_free_tab(av);
	}
	else
	{
		oldpwd1 = env->env[get_nblenv(env->env, "OLDPWD=")];
		env->env[get_nblenv(env->env, "OLDPWD=")] = newold1;
		free(oldpwd1);
	}
	free(oldpwd2);
}

void	set_pwd(t_env *env, char *new)
{
	char	*newpwd;
	char	*oldpwd1;
	char	*oldpwd2;
	char	**av;

	newpwd = (char *)malloc(sizeof(char) * (ft_strlen(new) + 5));
	newpwd[0] = 'P';
	newpwd[1] = 'W';
	newpwd[2] = 'D';
	newpwd[3] = '=';
	ft_strcpy(newpwd + 4, new);
	newpwd[ft_strlen(new) + 4] = 0;
	oldpwd2 = env->c_env[get_nblenv(env->c_env, "PWD=")];
	env->c_env[get_nblenv(env->c_env, "PWD=")] = ft_strdup(newpwd);
	free(oldpwd2);
	if (get_nblenv(env->env, "PWD=") == -1)
	{
		av = (char **)malloc(sizeof(char *) * 4);
		av[0] = ft_strdup("setenv");
		av[1] = ft_strdup("PWD");
		av[2] = new;
		av[3] = NULL;
		setanenv(env, av);
		ft_free_tab(av);
	}
	else
	{
		oldpwd1 = env->env[get_nblenv(env->env, "PWD=")];
		env->env[get_nblenv(env->env, "PWD=")] = newpwd;
		free(oldpwd1);
	}
}

int		move_dir(t_env *env, char *path)
{
	if (access(path, R_OK) != -1)
	{
		chdir(path);
		set_oldpwd(env);
		set_pwd(env, path);
		return (1);
	}
	else
		ft_error(9, path);
	return (-1);
}
