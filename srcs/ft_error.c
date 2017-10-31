/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:41:53 by juthierr          #+#    #+#             */
/*   Updated: 2017/10/31 22:41:55 by juthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_error2(int c, char *str)
{
	if (c == 8)
	{
		ft_putstr("unsetenv: ");
		ft_putstr(str);
		ft_putstr(" not found.\n");
	}
	else if (c == 9)
	{
		ft_putstr("cd: ");
		ft_putstr(str);
		ft_putstr(" not found or insufficient permission.\n");
	}
	else if (c == 10)
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putstr(str);
		ft_putchar('\n');
	}
}

void	ft_error(int c, char *str)
{
	if (c == 0)
	{
		ft_putstr_fd("my_sh : command not foud: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		exit(-1);
	}
	else if (c == 1)
		ft_putstr_fd("cd: too many arguments\n", 2);
	else if (c == 2)
	{
		ft_putstr_fd("cd: sting not in pwd: ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (c == 3)
		ft_putstr_fd("env: too many arguments.\n", 2);
	else if (c == 4)
		ft_putstr_fd("env: bad arguments.\n", 2);
	else if (c == 5)
		ft_putstr_fd("ft_minishell: can't open without env\n", 2);
	else if (c == 6)
		ft_putstr_fd("setenv usage: setenv [arg1] [arg2]\n", 2);
	else if (c == 7)
		ft_putstr_fd("unsetenv usage : unsetenv [arg1]\n", 2);
	else
		ft_error2(c, str);
}
