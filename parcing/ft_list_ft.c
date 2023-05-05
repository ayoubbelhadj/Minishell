/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:25:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/27 12:31:11 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

t_data	*ft_datanew(char *value)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (0);
	new->type = 1;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_data_addback(t_data **data, t_data *new)
{
	t_data	*temp;

	temp = *data;
	if (*data == NULL)
	{
		new->prev = NULL;
		*data = new;
	}
	else
	{
		if (!temp->next)
		{
			temp->next = new;
			new->prev = temp;
			return ;
		}
		while (temp->next)
			temp = temp->next;
		new->prev = temp;
		temp->next = new;
	}
}

void	ft_datadeloner(t_data *lst)
{
	if (!lst)
		return ;
	free(lst->value);
	free(lst);
}

void	ft_dataclear(t_data **lst)
{
	t_data	*temp;
	t_data	*t;

	if (!lst)
		return ;
	t = *lst;
	temp = *lst;
	while (temp)
	{
		temp = t->next;
		ft_datadeloner(t);
		t = temp;
	}
	*lst = NULL;
}
