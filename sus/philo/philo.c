/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:00:02 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/07 20:05:50 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_push	*node;

	node = (t_push *) ptr;
}

void	create_detach(t_push *list, t_list *head)
{
	while (1)
	{
		if (pthread_create(&list->p1, NULL, routine, head->linked_list) != 0)
			printf("Thread Error\n");
		pthread_detach(&list->p1);
		head->linked_list = head->linked_list->next;
		if (head->linked_list == list)
			break ;
	}
	while (1);
}

int	main(int ac, char **av)
{
	t_push	*list;
	t_list	*head;
	int		i;
	int		purpose;

	list = NULL;
	i = 1;
	if (ac == 5 || ac == 6)
	{
		if (one_two_three_four(av, 200) == 1 && \
			question_authority(av) == 1 && is_number(av))
		{
			purpose = ft_atoi(av[1]);
			while (i <= purpose)
				ft_lstadd_back(&list, lst_new(i++, head));
			create_detach(list, head);
		}
		else
			printf("Error\nNot Valid\n");
	}
	else
		return (0);
}
