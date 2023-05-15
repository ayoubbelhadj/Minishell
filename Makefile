# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 22:42:33 by aoudija           #+#    #+#              #
#    Updated: 2023/05/14 22:14:12 by aoudija          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror
DEPS = minishell.h

LFLAGS = -L ~/.brew/opt/readline/lib
IFLAGS = -I ~/.brew/opt/readline/include

LIBFT = $(addprefix  libft/, ft_isdigit ft_memset  ft_isprint ft_putendl_fd ft_itoa ft_strmapi \
		ft_bzero ft_putchar_fd  ft_atoi ft_strncmp var_compare ft_strcmp ft_memchr ft_striteri \
		ft_tolower  ft_strlen ft_putstr_fd ft_strlcat ft_calloc ft_strtrim \
		ft_toupper ft_isalnum ft_strrchr ft_str_not_in strlen_var ft_strlcpy ft_memcmp ft_split \
		ft_isalpha ft_memcpy ft_putnbr_fd ft_strnstr ft_strjoin \
		ft_isascii ft_memmove ft_strchr ft_strdup ft_strdupdup ft_substr \
		ft_lstiter ft_lstsize ft_lstclear ft_lstdelone ft_lstadd_back \
		ft_lstnew ft_lstadd_front two_d_strjoin ft_lstmap freed_strjoin ft_free ft_lstlast\
		get_next_line_utils get_next_line ft_realloc ft_strjoinfree ft_freetab ft_charjoin)

PARSING	= $(addprefix  parsing/, expand/ft_expand expand/ft_expand_utils expand/ft_expand_name\
			lexer/ft_add_data lexer/ft_cmd_type\
			utils/ft_list_ft utils/ft_utils utils/ft_data_checker utils/ft_cmd_ft utils/ft_data_checker2 utils/ft_inoutfile\
			utils/ft_heredoc_utils\
			ft_start ft_tokenizer ft_get_cmd ft_heredoc)
		
FILES = main builtins/ft_echo builtins/ft_env builtins/pwd builtins/cd/ft_cd builtins/cd/cd_utils builtins/export/export_utils \
		builtins/export/ft_export builtins/ft_unset builtins/export/fill_export \
		pipe/pipe pipe/pipe_utils pipe/cmd_list_size pipe/grant_access execute $(LIBFT) $(PARSING)

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
