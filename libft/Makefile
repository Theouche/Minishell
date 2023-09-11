# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlorne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 15:46:06 by tlorne            #+#    #+#              #
#    Updated: 2023/08/07 13:38:56 by tlorne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_fonction.c ft_divers_print.c get_next_line_bonus.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c  

OBJ = ${SRCS:.c=.o}

SRCS_BONUS = ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c 

OBJ_BONUS = ${SRCS_BONUS:.c=.o}

NAME = libft.a

all : ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

.c.o:
	gcc -c -Wall -Wextra -Werror $< -o ${<:.c=.o}

bonus: ${OBJ_BONUS}
	ar rcs ${NAME} ${OBJ_BONUS}

clean:
	rm -f ${OBJ}
	rm -f ${OBJ_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all
