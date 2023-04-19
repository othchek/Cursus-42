/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:32:40 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/19 22:06:28 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_pa(t_push **lst_a, t_push **lst_b, int i)
{
	t_push	*tmp;
	t_push	*last;

	if (!(*lst_b))
		return ;
	tmp = (*lst_b);
	last = (*lst_b);
	while (last->next != (*lst_b))
		last = last->next;
	tmp->prev->next = tmp->next;
	tmp->next->prev = last;
	(*lst_b) = tmp->next;
	ft_lstadd_front(lst_a, lst_new(tmp->data));
	if (i)
		write(1, "pa\n", 3);
	free(tmp);
}

void	inst_pb(t_push **stack_a, t_push **stack_b, int i)
{	
	t_push	*tmp;

	if (!*stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	tmp = (*stack_a)->prev;
	(*stack_a)->prev->prev->next = *stack_a;
	(*stack_a)->prev = (*stack_a)->prev->prev;
	ft_lstadd_front(stack_b, lst_new(tmp->data));
	if (i)
		write(1, "pb\n", 3);
	return ;
}
