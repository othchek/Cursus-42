/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_random_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:42:09 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/19 17:18:52 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	three_numbers(t_push **Morow)
// {
// 	if ((*Morow)->data > (*Morow)->next->data)
// 	{
// 		if ((*Morow)->next->data < (*Morow)->next->next->data
// 			&& (*Morow)->data < (*Morow)->next->next->data)
// 			inst_sa(Morow, 1);
// 		else if ((*Morow)->next->data > (*Morow)->next->next->data)
// 			sa_ra_rra(Morow, 1);
// 		else if ((*Morow)->next->data < (*Morow)->next->next->data
// 			&& (*Morow)->data > (*Morow)->next->next->data)
// 			inst_ra(Morow, 1);
// 	}
// 	else if ((*Morow)->data < (*Morow)->next->data)
// 	{
// 		if ((*Morow)->next->data > (*Morow)->next->next->data
// 			&& (*Morow)->data < (*Morow)->next->next->data)
// 			sa_ra_rra(Morow, 0);
// 		else if ((*Morow)->next->data > (*Morow)->next->next->data
// 			&& (*Morow)->data > (*Morow)->next->next->data)
// 			inst_rra(Morow, 1);
// 	}
// }
// void	sa_ra_rra(t_push **lst_a, int status)
// {
// 	if (status == 0)
// 	{
// 		inst_sa(lst_a, 1);
// 		inst_ra(lst_a, 1);
// 	}
// 	else if (status == 1)
// 	{
// 		inst_sa(lst_a, 1);
// 		inst_rra(lst_a, 1);
// 	}
// }

void	three_numbers(t_push **Morow)
{
	t_push	*head;

	head = (*Morow);
	cookielolxx(Morow);
	if (head->next->index == 0 && head->data < head->prev->data)
		inst_sa(Morow, 1);
	else if (head->prev->index == 0 && head->data > head->next->data)
	{
		inst_sa(Morow, 1);
		inst_rra(Morow, 1);
	}
	else if (head->next->index == 0 && head->data > head->prev->data)
		inst_ra(Morow, 1);
	else if (head->index == 0 && head->next->data > head->prev->data)
	{
		inst_sa(Morow, 1);
		inst_ra(Morow, 1);
	}
	else if (head->prev->index == 0 && head->data < head->next->data)
		inst_rra(Morow, 1);
}

void	sorted(t_push **Morow)
{
	t_push	*head;

	head = (*Morow);
	if (head->data < head->next->data && \
		head->next->data < head->prev->prev->data && \
		head->prev->prev->data < head->prev->data)
		return ;
	else
		three_numbers(Morow);
}
