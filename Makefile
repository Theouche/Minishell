# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlorne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 15:46:06 by tlorne            #+#    #+#              #
#    Updated: 2023/09/22 15:46:50 by tlorne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARIABLES ###

NAME = minishell

SRC = main.c init.c execute.c ft_parse_2.c handle_dollar.c ft_execute2.c \
		echo.c pwd.c env.c cd.c export.c export2.c unset.c \
		redir_db_droite.c redir_droite.c redir_gauche.c redir_db_gauche.c \
		utils.c redir_utils.c redir_utils_2.c handle_utils.c \
		signal.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

### COLORS ###

NOC         = "\033[0m"
BLACK       = "\033[1;30m"
RED         = "\033[1;31m"
GREEN       = "\033[1;32m"
YELLOW      = "\033[1;33m"
BLUE        = "\033[1;34m"
VIOLET      = "\033[1;35m"
CYAN        = "\033[1;36m"
WHITE       = "\033[1;37m"

### RULES ###

all:	${NAME}

${NAME}: ${OBJ}
	@make -C libft
	gcc -g ${CFLAGS} ${OBJ} libft/libft.a -lreadline -o ${NAME}
	@echo $(GREEN)Project successfully compiled${NOC}

clean :
	@make clean -C libft
	rm -f ${OBJ}

fclean : clean
	@make fclean -C libft
	rm -f ${NAME}

re : fclean all
