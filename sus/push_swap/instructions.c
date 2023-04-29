/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:40:05 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 15:28:17 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_sa(t_push **lst, int i)
{
	int	index;

	index = 0;
	if (ft_lstsize(*lst) < 2)
		ft_error("Error\nEmpty Stack");
	index = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = index;
	if (i)
		write(1, "sa\n", 3);
	return ;
}

void	inst_sb(t_push **lst, int i)
{
	int	index;
	int	purpose;

	index = 0;
	purpose = ft_lstsize(*lst);
	if (purpose < 2)
	{
		ft_error("Error\nEmpty Stack");
	}
	index = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = index;
	if (i)
		write(1, "sb\n", 3);
	return ;
}

void	inst_ss(t_push **heada, t_push **headb, int i)
{
	int	index;

	index = 0;
	inst_sa(heada, i);
	inst_sb(headb, i);
	return ;
}

void	inst_ra(t_push **lst, int i)
{
	(*lst) = (*lst)->next;
	if (i)
		write(1, "ra\n", 3);
	return ;
}

void	inst_rb(t_push **lst, int i)
{
	(*lst) = (*lst)->next;
	if (i)
		write(1, "rb\n", 3);
	return ;
}
