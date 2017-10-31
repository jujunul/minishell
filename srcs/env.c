/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:41:36 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:41:38 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**set_environ(char **environ)
{
	int		i;
	size_t	len;
	char	**env;

	i = -1;
	len = 0;
	while (environ[++i] != NULL)
		len++;
	env = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (environ[i] != NULL)
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

int		get_nblenv(char **env, char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], str, len) == 0)
			if (env[i][len] == '=' || env[i][len - 1] == '=')
				return (i);
		i++;
	}
	return (-1);
}

char	*get_lenv(char **env, char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], str, len) == 0)
			if (env[i][len] == '=' || env[i][len - 1] == '=')
				return (ft_strdup(env[i] + len));
		i++;
	}
	return (NULL);
}
