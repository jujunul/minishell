/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:42:29 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:42:31 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		count_av(t_env *env, char *line)
{
	int		i;
	int		sep;
	int		nbav;

	nbav = 0;
	i = env->ncmd - 1;
	sep = 0;
	while (line[++i] != 0 && (line[i] == ' ' || line[i] == '\t'))
		;
	if (line[i] == 0)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '"' && i++)
			sep = (sep == 1) ? 0 : 1;
		if (line[i] == ' ' && sep == 0)
		{
			nbav++;
			while (line[i + 1] != 0 && (line[i + 1] == ' ' || line[i + 1] == '\t'))
				i++;
		}
		i++;
	}
	return ((nbav += (line[i - 1] == ' ') ? 0 : 1));
}

int		verify_space(char *line, int i, int spe)
{
	if (line[i] == 0)
		return (0);
	if (line[i] == ' ' && spe == 0)
		return (0);
	return (1);
}

int		ft_strlenarg(char *line)
{
	int		i;
	int		j;
	int		spe;

	i = 0;
	j = 0;
	spe = 0;
	while (verify_space(line, i, spe) == 1)
	{
		if (line[i] == '"')
		{
			spe = (spe == 0) ? 1 : 0;
			j--;
		}
		j++;
		i++;
	}
	return (j);
}

char	*ft_strduparg(char *line, int *start)
{
	char	*dup;
	int		i;
	int		spe;
	int		first;
	int		nb;

	i = 0;
	spe = 0;
	first = 0;
	while (line[*start] == ' ')
		(*start)++;
	nb = ft_strlenarg(line + (*start));
	dup = (char *)malloc(sizeof(char) * (nb + 1));
	while (verify_space(line, *start, spe) == 1)
	{
		if (line[*start] == '"')
			spe = (spe == 0) ? 1 : 0;
		else
		{
			dup[i] = line[*start];
			i++;
		}
		(*start)++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**find_av(t_env *env, char *line, char *cmd)
{
	int		i;
	int		j;
	char	**av;
	int		nb;

	i = 1;
	j = 0;
	nb = count_av(env, line) + 1;
	av = (char **)malloc(sizeof(char *) * (nb + 1));
	av[0] = ft_strdup(cmd);
	while (i < nb)
	{
		av[i] = ft_strduparg(line, &(env->ncmd));
		i++;
	}
	av[i] = NULL;
	return (av);
}
