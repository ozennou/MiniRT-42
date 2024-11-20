/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:00:44 by mozennou          #+#    #+#             */
/*   Updated: 2024/02/24 19:29:13 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_lstsize(t_list *lst)
{
	int	res;

	res = 0;
	while (lst)
	{
		lst = lst->next;
		res++;
	}
	return (res);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = my_malloc(sizeof(t_list), 0);
	if (res == NULL)
		return (NULL);
	res->next = NULL;
	res->content = content;
	return (res);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	(*lst) = new;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}