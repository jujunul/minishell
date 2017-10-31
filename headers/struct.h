/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:28:38 by rduclos           #+#    #+#             */
/*   Updated: 2017/10/31 19:28:42 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "ft_minishell.h"

typedef struct		s_env
{
	char			**env;
	char			**c_env;
	char			**paths;
	char			*path;
	int				ncmd;
	int				leave;
	int				ret;
}					t_env;

#endif
