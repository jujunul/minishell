#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 12:04:09 by rduclos           #+#    #+#              #
#    Updated: 2017/10/31 19:32:07 by rduclos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell
FLAGS = -Wall -Wextra -Werror -g3
LIB = libft/
INCLUDES = headers/

CC = gcc

DIROBJ = objs/
DIRSRC = srcs/


SRC =	builtin.c cd.c cd_tools.c env.c ft_error.c main.c move_dir.c \
		parse_av.c parse_cmd.c setenv.c unsetenv.c

OBJ = $(SRC:%.c=$(DIROBJ)%.o)

all: init $(NAME)

init:
	@mkdir -p $(DIROBJ)
	@make -C $(LIB)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $(OBJ) -I $(INCLUDES) -L $(LIB) -lft -I $(LIB)
	@tput cuu1
	@echo "\033[2K\t\033[1;36m$(NAME)\t\t\033[0;32m[Ready]\033[0m"

$(DIROBJ)%.o: $(DIRSRC)%.c
	@echo "==> Compiling $<"
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INCLUDES) -I $(LIB)

clean:
	@make -C $(LIB) clean
	@rm -rf $(DIROBJ)
	@echo "[$(NAME)]--> Objects removed"

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)
	@echo "[$(NAME)]--> Program removed"

re: fclean all
