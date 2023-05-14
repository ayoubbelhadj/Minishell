/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:51:51 by aoudija           #+#    #+#             */
/*   Updated: 2023/05/14 18:49:11 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sort_exp(void)
{
	t_list	*temp;
	t_list	*tempp;
	char	*t;

	temp = g_data.exp;
	while (temp)
	{
		tempp = temp;
		while (tempp)
		{
			if (tempp->next && ft_strcmp(temp->content,
					tempp->next->content) > 0)
			{
				t = ft_strdup(temp->content);
				temp->content = tempp->next->content;
				tempp->next->content = t;
			}
			tempp = tempp->next;
		}
		temp = temp->next;
	}
}

void	fill_export(void)
{
	t_list	*temp;
	char	*t;
	char	*d;
	int		len;

	temp = g_data.env;
	g_data.exp = NULL;
	while (temp)
	{
		t = ft_substr(temp->content, 0, strlen_var(temp->content) + 1);
		len = ft_strlen(t);
		d = ft_strjoin(t, "\"");
		free(t);
		t = ft_substr(temp->content, len, ft_strlen(temp->content));
		d = ft_strjoin_frees1(d, t);
		free(t);
		t = ft_strjoin_frees1(d, "\"");
		d = ft_strjoin("declare -x ", t);
		ft_lstadd_back(&g_data.exp, ft_lstnew(d));
		free(t);
		temp = temp->next;
	}
	sort_exp();
}
