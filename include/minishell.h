/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 06:26:45 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/13 17:39:11 by abelhadj         ###   ########.fr       */
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
# include <dirent.h>
# include <termios.h>
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

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_eg
{
	t_list			*env;
	int				sig;
	int				fstdin;
	int				fstdout;
	int				exit_status;
}					t_eg;
t_eg	g_stuct;

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	int				in;
	int				out;
	int				error;
	struct s_cmd	*next;
}					t_cmd;

/* datalist */
void	ft_dataclear(t_token **lst);
void	ft_datadeloner(t_token *lst);
void	ft_data_addback(t_token **data, t_token *new);
t_token	*ft_datanew(char *value);

/* cmdlist */
t_cmd	*ft_cmdlast(t_cmd *cmd);
void	ft_cmdaddlist(t_cmd **cmd, t_cmd *new);
void	ft_cmddeloner(t_cmd *cmd);
void	ft_cmdclear(t_cmd	**cmd);
int		ft_cmdsize(t_cmd *cmd);

/* parcing */
char	*ft_expand(char *value);
void	ft_get_cmd(t_token **data, t_cmd **cmd);
int		ft_start(char *line, t_token *data, t_cmd **cmd);
t_token	*ft_datanew(char *value);
void	ft_data_addback(t_token **data, t_token *new);
int		ft_tokenizer(char *cmd, t_token **data);
int		check_syntax(char *cmd);
int		ft_quotes(char *cmd, int index);
int		ft_red_check(char c, char *cmd, int index);
void	ft_add_operator(t_token **data, char *cmd, int *i);
void	ft_add_str(t_token **data, char *cmd, int *index);
void	ft_cmd_type(t_token **data);
int		ft_check_data_syntax(t_token **data);
int		ft_check_cmd(char *str);
int		ft_ischard(int c);
void	ft_get_infile(t_cmd **cmd, char *value);
void	ft_get_outfile(t_cmd **cmd, char *value);
void	ft_get_append(t_cmd **cmd, char *value);
void	ft_inoutfile(t_token *tmp, t_cmd **cmd);
void	ft_getchar(char	*value, char **str, int i);
void	ft_getvarvalue(char *value, int *i, char **str, int	*flag);
char	*ft_getvalue(char *value, int *i);
char	*ft_dollarvalue(char *str);
char	*ft_expand_name(char *value);
int		ft_isquotein(char *str);

/* herdoc */
int		ft_heredoc(t_token **data);
char	*ft_heredocfile(char *delimiter);
int		ft_heredocwrite(char *line, char *del, int fd, char *delimiter);
void	ft_heredocsig(int sig);
char	*ft_expand_delimiter(char *delimiter);
char	*ft_namegenerator(void);

#endif
