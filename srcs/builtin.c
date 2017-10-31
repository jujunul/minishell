/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:40:55 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:40:58 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		do_echo(t_env *env, char **av)
{
	int		i;

	(void)env;
	i = 1;
	while (av[i] != NULL)
	{
		ft_putstr(av[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (1);
}

int		do_exit(t_env *env, char **av)
{
	(void)av;
	env->leave = 1;
	return (1);
}

int		verify_builtin(t_env *env, char *cmd, char **av)
{
	if (ft_strcmp("cd", cmd) == 0)
		return (do_cd(env, av));
	if (ft_strcmp("env", cmd) == 0)
		return (do_env(env, av));
	if (ft_strcmp("setenv", cmd) == 0)
		return (do_setenv(env, av));
	if (ft_strcmp("unsetenv", cmd) == 0)
		return (do_unsetenv(env, av));
	if (ft_strcmp("echo", cmd) == 0)
		return (do_echo(env, av));
	if (ft_strcmp("exit", cmd) == 0)
		return (do_exit(env, av));
	return (0);
}
