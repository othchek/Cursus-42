/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_random_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:42:09 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/14 18:30:12 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_push **Morow)
{	
	t_push *head;
	int i;

	i = 0;
	head = (*Morow);
	while (1)
	{
		head->index = ++i;
		head = head->next;
		if (head == (*Morow))
			break ;
	}
}

void	cookielolxx(t_push **Morow)
{
	t_push *head;
	t_push *head1;
	t_push *temp;
	
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
				break;
		}
		temp = (temp)->next;
		head1 = head1->next;
		if (head1 == *Morow)
			break;
		
	}
}