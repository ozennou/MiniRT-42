/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:37:24 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/07 21:56:16 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_addr_back(t_adress **head, t_adress *new)
{
	if (!head)
		return ;
	if (!*head)
	{
		*head = new;
		(*head)->last = new;
		return ;
	}
	(*head)->last->next = new;
	(*head)->last = new;
}

void	ft_addr_clear(t_adress **head)
{
	t_adress	*tmp;

	if (!head)
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		if (tmp->addr)
			free(tmp->addr);
		free(tmp);
	}
}

t_adress	*ft_addrnew(void *addr)
{
	t_adress	*new;

	new = malloc(sizeof(t_adress));
	if (!new)
		return (NULL);
	new->addr = addr;
	new->next = NULL;
	return (new);
}

void	*my_malloc(size_t size, int mode)
{
	void			*ptr;
	static t_adress	*head;

	if (!mode)
	{
		ptr = malloc(size);
		if (!ptr)
			return (ft_addr_clear(&head), exit(1), NULL);
		ft_addr_back(&head, ft_addrnew(ptr));
		return (ptr);
	}
	else
	{
		return (ft_addr_clear(&head), NULL);
	}
}
