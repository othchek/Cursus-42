/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_all_you_need.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:29:20 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/19 17:08:22 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*lst_new(int sata)
{
	t_push	*node;

	node = malloc(sizeof(t_push));
	node->index = 0;
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
		node = (node)->next;
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

void	cookielolxx(t_push **Morow)
{
	t_push	*head;
	int		i;

	i = 0;
	(*Morow)->index = 0;
	head = (*Morow);
	while (i < ft_lstsize(*Morow))
	{
		if ((*Morow)->data > head->data)
			(*Morow)->index++;
		head = head->next;
		if (head == *Morow)
		{
			if (i == ft_lstsize(*Morow) - 1)
				break ;
			(*Morow) = (*Morow)->next;
			head = head->next;
			(*Morow)->index = 0;
			i++;
		}
	}
	(*Morow) = (*Morow)->next;
}
