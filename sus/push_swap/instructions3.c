/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:32:40 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/03 22:05:51 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_pa(t_push **stack_a, t_push **stack_b, int i)
{
	t_push		*tmp;
	int			k;

	k = ft_lstsize(*stack_b);
	if (!*stack_b)
		return ;
	*stack_b = (*stack_b)->next;
	tmp = (*stack_b)->prev;
	(*stack_b)->prev->prev->next = *stack_b;
	(*stack_b)->prev = (*stack_b)->prev->prev;
	ft_lstadd_front(stack_a, lst_new(tmp->data));
	if (i)
		write(1, "pa\n", 3);
	if (k == 1)
		*stack_b = NULL;
	free(tmp);
}

void	inst_pb(t_push **stack_a, t_push **stack_b, int i)
{	
	t_push	*tmp;
	int		k;

	k = ft_lstsize(*stack_a);
	if (!*stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	tmp = (*stack_a)->prev;
	(*stack_a)->prev->prev->next = *stack_a;
	(*stack_a)->prev = (*stack_a)->prev->prev;
	ft_lstadd_front(stack_b, lst_new(tmp->data));
	if (i)
		write(1, "pb\n", 3);
	if (k == 1)
		*stack_a = NULL;
	free(tmp);
}

int	maximilien(t_push **headb, int half, int num)
{
	t_push	*tmp;
	int		counter;

	tmp = *headb;
	counter = 0;
	while ((*headb))
	{
		if (tmp->index == num)
			break ;
		counter++;
		tmp = tmp->next;
		if (tmp->next == (*headb))
			break ;
	}
	if (counter <= half)
		return (0);
	return (1);
}

void	ft_lstclear(t_push **lst)
{
	t_push	*purpose;
	t_push	*count;
	int		i;

	if (lst)
	{
		purpose = *lst;
		count = purpose->next;
		i = ft_lstsize(*lst);
		while (i--)
		{
			purpose = count;
			free(purpose);
			count = count->next;
		}
	}
}
