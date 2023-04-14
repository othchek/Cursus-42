/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:32:40 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/14 14:21:40 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_pa(t_push **stack_b, t_push **stack_a, int i)
{
	t_push	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev->next = (*stack_b)->next;
	tmp->next = *stack_a;
	(*stack_a)->prev->next = tmp;
	*stack_a = tmp;
	if (i)
		write(1, "pa\n", 3);
	return ;
}

void    inst_pb(t_push **stack_a, t_push **stack_b, int i)
{
    t_push    *tmp;

    if (!*stack_a)
        return ;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
	(*stack_a)->prev->next = (*stack_a)->next;
    tmp->next = *stack_b;
	(*stack_b)->prev->next = tmp;
    *stack_b = tmp;
	if (i)
    	write(1, "pb\n", 3);
    return ;
}