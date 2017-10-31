/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:41:11 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:41:15 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		rm_one_dir(t_env *env)
{
	char	*pwd;
	char	*new;
	int		i;
	int		size;
	int		ret;

	i = 0;
	size = 0;
	if ((pwd = get_lenv(env->env, "PWD=")) == NULL)
		pwd = get_lenv(env->c_env, "PWD=");
	while (pwd[i] != 0)
	{
		if (pwd[i] == '/')
			size = i;
		i++;
	}
	new = (char *)malloc(sizeof(char) * (size + 1));
	new = ft_strncpy(new, pwd, size);
	free(pwd);
	if (new[0] == 0)
		ret = move_dir(env, "/");
	else
		ret = move_dir(env, new);
	free(new);
	return (ret);
}

int		add_one_dir(t_env *env, char *way)
{
	char	*pwd;
	char	*new;
	int		len1;
	int		len2;
	int		ret;

	if ((pwd = get_lenv(env->env, "PWD=")) == NULL)
		pwd = get_lenv(env->c_env, "PWD=");
	len1 = ft_strlen(pwd);
	len2 = ft_strlen(way);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	new = ft_strcpy(new, pwd);
	new[len1] = '/';
	ft_strcpy(new + len1 + 1, way);
	free(pwd);
	ret = move_dir(env, new);
	free(new);
	return (ret);
}
