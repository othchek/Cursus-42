/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_random_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:42:09 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/16 15:55:14 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cookielolxx(t_push **Morow)
{
	t_push	*head;
	t_push	*head1;
	t_push	*temp;

	temp = (*Morow);
	head1 = (*Morow);
	while (head1)
	{
		head = *Morow;
		while (head)
		{
			if (temp->data > head->data)
				temp->index++;
			head = head->next;
			if (head == *Morow)
				break ;
		}
		temp = (temp)->next;
		head1 = head1->next;
		if (head1 == *Morow)
			return (temp->index);
	}
	return (0);
}

void	three_numbers(t_push **Morow)
{
	t_push	*head;

	head = (*Morow);
	while (head)
	{
		if (cookielolxx(&head->next) == 0 && head->data < head->prev->data)
			inst_sa(Morow, 1);
		else if (cookielolxx(&head->prev) == 0 && head->data > head->next->data)
		{
			inst_sa(Morow, 1);
			inst_rra(Morow, 1);
			break ;
		}
		else if (cookielolxx(&head->next) == 0 && head->data > head->prev->data)
		{
			inst_ra(Morow, 1);
			break ;
		}
		else if (cookielolxx(&head) == 0 && head->next->data > head->prev->data)
		{
			inst_sa(Morow, 1);
			inst_ra(Morow, 1);
			break ;
		}
		else if (cookielolxx(&head->prev) == 0 && head->data < head->next->data)
		{
			inst_rra(Morow, 1);
			break ;
		}
		if (head == *Morow)
			break ;
	}
}

// void three_numbers1(t_push **Morow)
// {
// 	t_push 
// 	if (cookielolxx(&head->next) == 0 && head->data > head->prev->data)
// 	{
// 		inst_ra(Morow, 1);
// 		break ;
// 	}
// 	else if (cookielolxx(&head) == 0 && head->next->data > head->prev->data)
// 	{
// 		inst_sa(Morow, 1);
// 		inst_ra(Morow, 1);
// 		break ;
// 	}
// 	else if (cookielolxx(&head->prev) == 0 && head->data < head->next->data)
// 	{
// 		inst_rra(Morow, 1);
// 		break ;
// 	}
// }