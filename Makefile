# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 22:42:33 by aoudija           #+#    #+#              #
#    Updated: 2023/04/20 20:05:52 by aoudija          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror


LFLAG = /Users/aoudija/.brew/opt/readline

DEPS = minishell.h

LIBB = -L ${LFLAG}/lib -lreadline

INC = -I includes -I ${LFLAG}/include

FILES = main.c builtins.c libft/ft_isdigit.c libft/ft_memset.c \
		libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_isprint.c \
		libft/ft_strlcat.c libft/ft_atoi.c libft/ft_substr.c libft/ft_putchar_fd.c \
		libft/ft_strlcpy.c libft/ft_tolower.c libft/ft_bzero.c libft/ft_strlen.c libft/ft_putstr_fd.c \
		libft/ft_toupper.c libft/ft_calloc.c libft/ft_memchr.c libft/ft_isalnum.c libft/ft_striteri.c \
		libft/ft_putendl_fd.c \
		libft/ft_memcmp.c libft/ft_split.c libft/ft_strncmp.c libft/ft_putnbr_fd.c \
		libft/ft_isalpha.c libft/ft_memcpy.c libft/ft_strchr.c \
		libft/ft_strnstr.c libft/ft_isascii.c libft/ft_memmove.c libft/ft_strdup.c \
		libft/ft_strrchr.c libft/ft_itoa.c libft/ft_strmapi.c \

OBG = $(FILES:.c=.o)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

all : $(NAME)

$(NAME) : $(OBG)
	$(CC) $(CFLAGS) $(INC) $(OBG) -o $(NAME) $(LIBB)

clean:
	rm -f $(OBG)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re
