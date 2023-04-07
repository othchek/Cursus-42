/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_all_you_need.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:29:20 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/05 21:27:50 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*lst_new(int sata)
{
	t_push	*node;

	node = malloc(sizeof(t_push));
	node->data = sata;
	node->next = node;
	node->prev = node;
	return (node);
}

void	ft_lstadd_back(t_push **lst, t_push *new)
{
	t_push	*node;
	t_push	*head;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	node = (*lst);
	head = (*lst);
	while (node->next != head)
		*lst = (*lst)->next;
	node->next = new;
	new->next = head;
	new->prev = node;
	head->prev = new;
}

void	ft_lstadd_front(t_push **lst, t_push *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = (*lst);
	new->prev = (*lst)->prev;
	(*lst)->prev->next = new;
	(*lst)->prev = new;
	(*lst) = new;
}

int	ft_lstsize(t_push *lst)
{
	int		index;
	t_push	*tmp;

	tmp = lst;
	index = 0;
	while (lst)
	{
		index++;
		lst = lst->next;
		if (lst == tmp)
			break ;
	}
	return (index);
}
