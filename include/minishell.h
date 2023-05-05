/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 06:26:45 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/05 16:45:16 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <signal.h>
# include "../libft/libft.h"

typedef enum e_type
{
	NONE,
	CMD,
	ARG,
	INFILE,
	OUTFILE,
	APPOUT,
	DELIMITER,
	OUTPUT,
	APPEND,
	INPUT,
	PIPE,
	HERDOC,
}	t_type;

typedef enum e_error
{
	SUCCESS,
	ERROR,
	ERROR_2,
	CMD_NOT_EXECUT = 126,
	CMD_NOT_FOUND = 127,
	SYNTAX_ERROR = 258
}	t_error;

typedef struct s_data
{
	char			*value;
	t_type			type;
	struct s_data	*prev;
	struct s_data	*next;
}					t_data;

typedef struct s_eg
{
	t_list			*env;
	int				exit_status;
}					t_eg;
t_eg	g_stuct;

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	char			**red_args;
	struct s_cmd	*next;
}					t_cmd;

/* datalist */
void	ft_dataclear(t_data **lst);
void	ft_datadeloner(t_data *lst);
void	ft_data_addback(t_data **data, t_data *new);
t_data	*ft_datanew(char *value);

/* cmdlist */
t_cmd	*ft_cmdlast(t_cmd *cmd);
void	ft_cmdaddlist(t_cmd **cmd, t_cmd *new);
void	ft_cmddeloner(t_cmd *cmd);
void	ft_cmdclear(t_cmd	**cmd);

/* parcing */
void	ft_get_cmd(t_data **data, t_cmd **cmd);
int		ft_start(char *line, t_data *data, t_cmd *cmd);
t_data	*ft_datanew(char *value);
void	ft_data_addback(t_data **data, t_data *new);
void	ft_tokenizer(char *cmd, t_data **data);
int		check_syntax(char *cmd);
int		quotes(char *cmd, int index);
int		ft_opt_check(char c, char *cmd, int index);
void	ft_add_operator(t_data **data, char *cmd, int *i);
void	ft_add_str(t_data **data, char *cmd, int *index);
void	ft_cmd_type(t_data **data);
int		ft_check_data_syntax(t_data **data);

#endif
