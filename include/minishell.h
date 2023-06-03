/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 06:26:45 by abelhadj          #+#    #+#             */
/*   Updated: 2023/05/30 15:31:19 by aoudija          ###   ########.fr       */
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
# include <sys/errno.h>
# include "../libft/libft.h"

//parser
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
	int				err;
	int				flag;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

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
void		ft_dataclear(t_token **lst);
void		ft_datadeloner(t_token *lst);
void		ft_data_addback(t_token **data, t_token *new);
t_token		*ft_datanew(char *value);

/* cmdlist */
t_cmd		*ft_cmdlast(t_cmd *cmd);
void		ft_cmdaddlist(t_cmd **cmd, t_cmd *new);
void		ft_cmddeloner(t_cmd *cmd);
void		ft_cmdclear(t_cmd	**cmd);
int			ft_cmdsize(t_cmd *cmd);

/* parsing */
char		*ft_expand(char *value);
void		ft_get_cmd(t_token **data, t_cmd **cmd);
int			ft_start(char *line, t_token *data, t_cmd **cmd);
t_token		*ft_datanew(char *value);
void		ft_data_addback(t_token **data, t_token *new);
int			ft_tokenizer(char *cmd, t_token **data);
int			check_syntax(char *cmd);
int			ft_quotes(char *cmd, int index);
int			ft_red_check(char c, char *cmd, int index);
void		ft_operator_add(t_token **data, char *cmd, int *index);
void		ft_str_add(t_token **data, char *cmd, int *index);
void		ft_cmd_type(t_token **data);
int			ft_check_data_syntax(t_token **data);
int			ft_check_cmd(char *str);
int			ft_ischard(int c);
void		ft_get_infile(t_cmd **cmd, char *value, t_token *tmp);
void		ft_get_outfile(t_cmd **cmd, char *value, t_token *tmp);
void		ft_get_append(t_cmd **cmd, char *value, t_token *tmp);
void		ft_inoutfile(t_token *tmp, t_cmd **cmd);
void		ft_getchar(char	*value, char **str, int i);
void		ft_getvarvalue(char *value, int *i, char **str, int	*flag);
char		*ft_getvalue(char *value, int *i);
char		*ft_dollarvalue(char *str);
char		*ft_expand_name(char *value);
int			ft_isquotein(char *str);

/* herdoc */
int			ft_heredoc(t_token **data);
char		*ft_heredocfile(char *delimiter);
int			ft_heredocwrite(char *line, char *del, int fd, char *delimiter);
void		ft_heredocsig(int sig);
char		*ft_expand_delimiter(char *delimiter);
char		*ft_namegenerator(void);

void		handler(int sig);

/*------ EXECUTION---------*/

typedef struct s_e_data
{
	t_list	*env;
	t_list	*exp;
	int		exit_status;
	int		sig;
	int		fstdin;
	int		fstdout;
	int		sigflag;
}			t_e_data;
t_e_data	g_data;

void		*ft_free(char **table);
char		**ft_strdupdup(char **tab);
void		execute(t_cmd	*cmd);

int			var_is_valid(t_cmd *cmd, char *args);
/*export*/
void		export_only(t_cmd *cmd);
int			count_char(char *str, char c);
char		*exp_plus(char *exp_old, char *exp_new);
char		*env_plus(char *env_old, char *env_new);
void		fill_export(void);
void		sort_exp(void);
char		*exp_new_content(char *arg);
int			exp_matching_vars(t_cmd *cmd, int i, int plus);
int			env_new(t_cmd *cmd, int i, int plus);
void		ft_export(t_cmd	*cmd);
void		export_norm1(t_cmd *cmd, int i);
void		export_norm2(t_cmd *cmd, int i);
char		*remove_char(char *str, char c);

int			check(t_cmd *cmd, int i);

/*cd*/
void		search_var(char *str, char *new);
void		change_env(char *str, char *new);
void		change_exp(char *str, char *new);
void		norma_cd_1(t_cmd *cmd, char *cwd, int i);
void		norma_cd_2(char *cwd);
char		*found_var(char *var);
void		cd(t_cmd *cmd);
/*unset*/
void		ft_unset(t_cmd *cmd);
/*lonelymofos*/
void		fill_env(char **envv);
void		pwd(t_cmd *cmd);
void		ft_env(t_cmd *cmd);
void		ft_echo(t_cmd *cmd);
void		ft_exit(t_cmd *cmd);
int			is_builtin(t_cmd *cmd);
void		exec_builtin(t_cmd *cmd);
/*pipe*/
void		d_n_c_first(t_cmd *cmd, int **fd, int i);
void		d_n_c_middle(t_cmd *cmd, int **fd, int i);
void		d_n_c_last(t_cmd *cmd, int **fd, int i);
void		execute_it(t_cmd *cmd);
char		**put_in_tab(void);
char		**path_env(void);
char		*cmd_path(t_cmd *cmd);
char		*grant_access(t_cmd *cmd);
char		*builtinnot_path(t_cmd *cmd);
int			cmd_list_size(t_cmd *lst);
void		exec_command(t_cmd *cmd, char *s, char **envv);
void		close_fdeez(t_cmd *cmd, int **fd);
void		first_cmd(t_cmd *cmd, int **fd, int *i, char **env);
void		last_cmd(t_cmd *cmd, int **fd, int *i, char **env);
void		middle_cmd(t_cmd *cmd, int **fd, int *i, char **env);

#endif
