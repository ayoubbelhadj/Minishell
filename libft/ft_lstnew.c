/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:10:50 by abelhadj          #+#    #+#             */
/*   Updated: 2023/04/27 14:02:06 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list *));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
