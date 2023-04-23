/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_random_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:42:09 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/23 16:09:49 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	sorted(t_push **heada, t_push **headb)
{
	t_push	*head;

	(void)headb;
	head = (*heada);
	while ((*heada)->next != head)
	{
		if ((*heada)->data < (*heada)->next->data)
			(*heada) = (*heada)->next;
		else
			return (0);
	}
	return (1);
}
