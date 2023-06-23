/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 23:03:56 by otchekai          #+#    #+#             */
/*   Updated: 2023/06/23 21:08:09 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pleased_to_die(t_list *head)
{
	t_push	*tmp;
	int		i;

	i = 0;
	tmp = head->linked_list;
	while (1)
	{
		pthread_mutex_lock(&tmp->manger);
		i = jesus_manger(head->linked_list);
		if (i == head->philo)
			return ;
		pthread_mutex_unlock(&tmp->manger);
		pthread_mutex_lock(&head->linked_list->death);
		if (in_time() - head->linked_list->ate > head->death)
		{
			can_trees_feel_pain(head->linked_list, "died");
			return ;
		}
		pthread_mutex_unlock(&head->linked_list->death);
		head->linked_list = head->linked_list->next;
	}
}

long long	in_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	destruction(t_push *head)
{
	t_push	*tmp;
	int		i;

	i = 0;
	tmp = head;
	while (i++ < head->struct_ss->philo)
	{
		pthread_mutex_destroy(&tmp->death);
		pthread_mutex_destroy(&tmp->manger);
		pthread_mutex_destroy(&tmp->mutex);
		tmp = tmp->next;
	}
	pthread_mutex_destroy(&head->struct_ss->danger);
	pthread_mutex_destroy(&head->struct_ss->eat_mutex);
}
