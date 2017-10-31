/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:42:39 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:42:41 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*find_cmd(t_env *env, char *line)
{
	int		j;
	char	*cmd;
	int		sep;

	j = 0;
	env->ncmd = 0;
	sep = 0;
	cmd = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[env->ncmd] != '\0')
	{
		if (line[env->ncmd] == '"')
		{
			sep = (sep == 1) ? 0 : 1;
			env->ncmd++;
		}
		if (line[env->ncmd] == ' ' && sep == 0)
			break;
		cmd[j] = line[env->ncmd];
		j++;
		env->ncmd++;
	}
	cmd[j] = 0;
	return (cmd);
}
