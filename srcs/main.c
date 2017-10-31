/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:42:57 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:42:59 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	do_execve(t_env *env, char *cmd, char **av)
{
	int		i;
	int		child_status;
	pid_t	father;
	char	*pcmd;

	i = 0;
	if ((env->path = get_lenv(env->env, "PATH=")) == NULL || env->path[0] == 0)
		env->path = get_lenv(env->c_env, "PATH=");
	env->paths = ft_strsplit(env->path, ':');
	father = fork();
	if (father > 0)
		waitpid(father, &child_status, 0);
	if (father == 0)
	{
		if (execve(cmd, av, env->env) == -1)
		{
			while (env->paths[i] != NULL)
			{
				pcmd = ft_addpath(env->paths[i++], cmd);
				execve(pcmd, av, env->env);
				free(pcmd);
			}
			ft_error(0, cmd);
		}
	}
}

void	exec_shell(t_env *env, char *cmd, char **av)
{
	if (verify_builtin(env, cmd, av) == 0)
	{
		do_execve(env, cmd, av);
		free(env->path);
		ft_free_tab(env->paths);
	}
}

void	parse_line(t_env *env, char *line)
{
	char	*cmd;
	char	**av;

	cmd = find_cmd(env, line);
	if (cmd[0] != 0)
	{
		av = find_av(env, line, cmd);
		exec_shell(env, cmd, av);
		ft_free_tab(av);
	}
	free(cmd);
}

void	my_shell(t_env *env)
{
	char	*line;

	line = NULL;
	ft_putstr("$>");
	while (env->leave == 0 && get_next_line(0, &line) > 0)
	{
		parse_line(env, line);
		free(line);
		if (env->leave == 0)
			ft_putstr("$>");
	}
}

int		main(int ac, char **av, char **env)
{
	t_env	my_env;

	(void)ac;
	(void)av;
	if (env == NULL)
	{
		ft_error(5, NULL);
		return (-1);
	}
	my_env.leave = 0;
	my_env.ret = 0;
	my_env.env = set_environ(env);
	my_env.c_env = set_environ(env);
	my_shell(&my_env);
	return (my_env.ret);
}
