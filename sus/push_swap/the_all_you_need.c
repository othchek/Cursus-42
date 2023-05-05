/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_all_you_need.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:29:20 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/05 00:06:37 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*lst_new(int sata)
{
	t_push	*node;

	node = malloc(sizeof(t_push));
	if (!node)
		exit(1);
	node->index = 0;
	node->data = sata;
	node->next = node;
	node->prev = node;
	return (node);
}

t_print	*lst_new2(char *sata)
{
	t_print	*node;

	node = malloc(sizeof(t_print));
	if (!node)
		exit(1);
	node->data = sata;
	node->next = NULL;
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
		node = (node)->next;
	node->next = new;
	new->next = head;
	new->prev = node;
	head->prev = new;
}

void	ft_lstadd_back2(t_print **lst, t_print *new)
{
	t_print	*node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	node = (*lst);
	while (node->next)
		node = (node)->next;
	node->next = new;
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
