# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 22:42:33 by aoudija           #+#    #+#              #
#    Updated: 2023/04/24 06:54:52 by aoudija          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror

DEPS = minishell.h

LFLAGS = -L ~/.brew/opt/readline/lib
IFLAGS = -I ~/.brew/opt/readline/include

LIBFT = $(addprefix  libft/, ft_isdigit ft_memset  ft_isprint ft_putendl_fd ft_itoa ft_strmapi \
		ft_bzero ft_putchar_fd  ft_atoi ft_strncmp ft_memchr ft_striteri \
		ft_tolower  ft_strlen ft_putstr_fd ft_strlcat ft_calloc ft_strtrim \
		ft_toupper ft_isalnum ft_strrchr  ft_strlcpy ft_memcmp ft_split \
		ft_isalpha ft_memcpy ft_putnbr_fd ft_strnstr ft_strjoin \
		ft_isascii ft_memmove ft_strchr ft_strdup ft_strdupdup ft_substr \
		ft_lstiter ft_lstsize ft_lstclear ft_lstdelone ft_lstadd_back \
		ft_lstnew ft_lstadd_front two_d_strjoin ft_lstmap freed_strjoin ft_free ft_lstlast\
		get_next_line_utils get_next_line)

FILES = main builtins execute $(LIBFT)

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER  = include/minishell.h
INCLUDES=  -I include



all: $(NAME) 

$(NAME): $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY)	- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(OBJ) $(IFLAGS) $(INCLUDES) -o $(NAME) $(LFLAGS) -lreadline
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"


	
%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re
