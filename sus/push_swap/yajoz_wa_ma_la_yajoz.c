/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yajoz_wa_ma_la_yajoz.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:21:17 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/05 15:55:52 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norinatte(t_print *print)
{
	t_print	*oldprint2;

	oldprint2 = print;
	while (oldprint2)
	{
		if ((!ft_strncmp("ra\n", oldprint2->data, 3) && \
		oldprint2->next && !ft_strncmp("rb\n", oldprint2->next->data, 3)) || \
		(!ft_strncmp("rb\n", oldprint2->data, 3) && oldprint2->next
				&& !ft_strncmp("ra\n", oldprint2->next->data, 3)))
		{
			write(1, "rr\n", 3);
			oldprint2 = oldprint2->next;
		}
		else if (!ft_strncmp("pb\n", oldprint2->data, 3) && oldprint2->next
			&& !ft_strncmp("pa\n", oldprint2->next->data, 3))
		oldprint2 = oldprint2->next;
		else
			ft_putstr_fd(oldprint2->data, 1);
		oldprint2 = oldprint2->next;
	}
}

void	normanitte(t_print *print, t_print *print2)
{
	t_print	*oldprint;
	t_print	*oldprint2;

	oldprint = print;
	oldprint2 = print2;
	while (oldprint)
	{
		if ((!ft_strncmp("ra\n", oldprint->data, 3) && oldprint->next
			&& !ft_strncmp("rb\n", oldprint->next->data, 3)) || (!ft_strncmp("rb\n", oldprint->data, 3) && oldprint->next && !ft_strncmp("ra\n", oldprint->next->data, 3)))
		{
			ft_lstadd_back2(&oldprint2, lst_new2("rr\n"));
			oldprint = oldprint->next;
		}
		else if (!ft_strncmp("pb\n", oldprint->data, 3) && oldprint->next && !ft_strncmp("pa\n", oldprint->next->data, 3))
			oldprint = oldprint->next;
		else
			ft_lstadd_back2(&oldprint2, lst_new2(oldprint->data));
		oldprint = oldprint->next;
	}
	ft_clear_lst(&oldprint2);
	norinatte(print);
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
