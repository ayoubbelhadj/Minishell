# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 22:42:33 by aoudija           #+#    #+#              #
#    Updated: 2023/05/05 16:45:37 by abelhadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror

DEPS = minishell.h

LFLAGS = -L ~/.brew/opt/readline/lib -lreadline 
IFLAGS = -I ~/.brew/opt/readline/include

LIBFT = $(addprefix  libft/, ft_charjoin ft_isdigit ft_memset  ft_isprint ft_putendl_fd ft_itoa ft_strmapi \
		ft_bzero ft_putchar_fd  ft_atoi ft_strncmp ft_memchr ft_striteri \
		ft_tolower  ft_strlen ft_putstr_fd ft_strlcat ft_calloc ft_strtrim \
		ft_toupper ft_isalnum ft_strrchr  ft_strlcpy ft_memcmp ft_split \
		ft_isalpha ft_memcpy ft_putnbr_fd ft_strnstr ft_strjoin \
		ft_isascii ft_memmove ft_strchr ft_strdup ft_substr ft_strcmp\
		ft_lstiter ft_lstsize ft_lstclear ft_lstdelone ft_lstadd_back \
		ft_lstnew ft_lstadd_front ft_lstmap ft_lstlast ft_freetab\
		get_next_line_utils get_next_line ft_realloc ft_strjoinfree)
PARCING	= $(addprefix  parcing/, ft_list_ft ft_start ft_tokenizer ft_utils ft_add_data\
		ft_cmd_type ft_data_checker ft_get_cmd ft_cmd_ft)

FILES = main builtins $(LIBFT) $(PARCING)

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER  = include/minishell.h
INCLUDES=  -I include 



all: $(NAME) 

$(NAME): $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY)	- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(OBJ) $(FLAGS)  $(IFLAGS) $(INCLUDES) -o $(NAME) $(LFLAGS)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"


	
%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) $(INCLUDES) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re
