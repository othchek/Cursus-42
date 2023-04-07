/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:40:05 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/07 17:12:26 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_sa(t_push **lst, int i)
{
	int	index;

	index = 0;
	if (ft_lstsize(*lst) < 2)
		ft_error("Error\nEmpty Stack");
	if (i)
		write(1, "sa\n", 3);
	index = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = index;
	return ;
}

void	inst_sb(t_push **lst, int i)
{
	int	index;

	index = 0;
	if (ft_lstsize(*lst) < 2)
		ft_error("Error\nEmpty Stack");
	if (i)
		write(1, "sb\n", 3);
	index = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = index;
	return ;
}

void	inst_ss(t_push **lst, int i)
{
	int	index;

	index = 0;
	inst_sa(lst, i);
	inst_sb(lst, i);
	return ;
}

void	inst_ra(t_push **lst, int i)
{
	if (i)
		write(1, "ra\n", 3);
	(*lst) = (*lst)->next;
	return ;
}

void	inst_rb(t_push **lst, int i)
{
	if (i)
		write(1, "rb\n", 3);
	(*lst) = (*lst)->next;
	return ;
}
