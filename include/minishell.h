/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 06:26:45 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/24 07:01:23 by aoudija          ###   ########.fr       */
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

void	ft_echo(char *cmd);
typedef struct s_data
{
	char	**env;
	t_list	*cmd;
	char	**cmd_tab;
} t_data;
t_data	*data;
void	*ft_free(char **table);
char	**ft_strdupdup(char **tab);
void	execute(char *cmd);
void	ft_env(void);
void	ft_echo(char *cmd);
void	ft_export(char *cmd);


#endif
