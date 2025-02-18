/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_random_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:42:09 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/05 15:23:16 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_push **Morow, t_print **headc)
{
	t_push	*head;

	head = (*Morow);
	cookielolxx(Morow);
	if (head->next->index == 0 && head->data < head->prev->data)
		inst_sa(Morow, headc, 1);
	else if (head->prev->index == 0 && head->data > head->next->data)
	{
		inst_sa(Morow, headc, 1);
		inst_rra(Morow, headc, 1);
	}
	else if (head->next->index == 0 && head->data > head->prev->data)
		inst_ra(Morow, headc, 1);
	else if (head->index == 0 && head->next->data > head->prev->data)
	{
		inst_sa(Morow, headc, 1);
		inst_ra(Morow, headc, 1);
	}
	else if (head->prev->index == 0 && head->data < head->next->data)
		inst_rra(Morow, headc, 1);
}

int	is_sorted(t_push **lst)
{
	t_push	*head;

	head = (*lst);
	while (head)
	{
		if (head->data < head->next->data)
			head = head->next;
		else
			return (0);
		if (head->next == (*lst))
			break ;
	}
	return (1);
}

void	allfree(char **str)
{
	int		k;

	k = 0;
	while (str[k])
	{
		free(str[k]);
		k++;
	}
	free(str);
}

void	ft_clear_lst(t_print **lst)
{
	t_print	*nextlst;
	t_print	*currentlst;

	if (!lst || !(*lst))
		return ;
	nextlst = *lst;
	while (nextlst)
	{
		currentlst = nextlst;
		nextlst = nextlst->next;
		free(currentlst);
	}
	nextlst = NULL;
}
