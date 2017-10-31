/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:28:00 by rduclos           #+#    #+#             */
/*   Updated: 2017/10/31 19:30:05 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <unistd.h>
# include "libft.h"
# include "struct.h"

/*
** builtin.c
*/
int		do_echo(t_env *env, char **av);
int		do_exit(t_env *env, char **av);
int		verify_builtin(t_env *env, char *cmd, char **av);
/*
** cd.c
*/
void	move_from_home(t_env *env, char *way);
void	move_back(t_env *env);
void	usual_cd(t_env *env, char *av);
void	dual_cd(t_env *env, char **av);
int		do_cd(t_env *env, char **av);
/*
** cd_tools.c
*/
int		rm_one_dir(t_env *env);
int		add_one_dir(t_env *env, char *way);
/*
** env.c
*/
char	**set_environ(char **environ);
int		get_nblenv(char **env, char *str);
char	*get_lenv(char **env, char *str);
/*
** ft_error.c
*/
void	ft_error2(int c, char *str);
void	ft_error(int c, char *str);
/*
** main.c
*/
void	do_execve(t_env *env, char *cmd, char **av);
void	exec_shell(t_env *env, char *cmd, char **av);
void	parse_line(t_env *env, char *line);
void	my_shell(t_env *env);
int		main(int ac, char **av, char **env);
/*
** move_dir.c
*/
void	set_oldpwd(t_env *env);
void	set_pwd(t_env *env, char *new);
int		move_dir(t_env *env, char *path);
/*
** parse_av.c
*/
int		count_av(t_env *env, char *line);
int		verify_space(char *line, int i, int spe);
int		ft_strlenarg(char *line);
char	*ft_strduparg(char *line, int *start);
char	**find_av(t_env *env, char *line, char *cmd);
/*
** parse_cmd.c
*/
char	*find_cmd(t_env *env, char *line);
/*
** setenv.c
*/
int		do_env(t_env *env, char **av);
void	change_one_env(t_env *env, char **av);
char	*addone_env(char **av);
void	setanenv(t_env *env, char **av);
int		do_setenv(t_env *env, char **av);
/*
** unsetenv.c
*/
int		do_unsetenv(t_env *env, char **av);

#endif
