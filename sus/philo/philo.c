/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:00:02 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/20 14:56:16 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	in_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	kadir_chi_haja(t_push *node, char *str)
{
	if (ft_strncmp(str, "died", 4) == 0)
		printf("\033[0;31m%lld\033[0m \033[0;31m%d\033[0m \033[0;31m%s\033[0m 💀\n",
        	(in_time() - node->struct_ss->time), node->data, str);
	else
		printf("\033[0;34m%lld\033[0m \033[0;31m%d\033[0m \033[0;33m%s\033[0m 🗿\n",
			(in_time() - node->struct_ss->time), node->data, str);
}

void	*routine(void *ptr)
{
	t_push		*node;

	node = (t_push *) ptr;
	if ((node->data % 2) == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&node->mutex);
		kadir_chi_haja(node, "has taken a fork");
		pthread_mutex_lock(&node->next->mutex);
		kadir_chi_haja(node, "has taken a fork");
		pthread_mutex_lock(&node->msoos);
		node->ate = in_time();
		kadir_chi_haja(node, "is eating");
		pthread_mutex_unlock(&node->msoos);
		u_sleep(node->struct_ss->eat);
		pthread_mutex_unlock(&node->mutex);
		pthread_mutex_unlock(&node->next->mutex);
		kadir_chi_haja(node, "is sleeping");
		u_sleep(node->struct_ss->sleep);
		kadir_chi_haja(node, "is thinking");
	}
	return (0);
}

void	create_detach(t_list *head)
{
	head->linked_list2 = head->linked_list;
	head->time = in_time();
	while (1)
	{
		head->linked_list->ate = in_time();
		if (pthread_create(&head->linked_list->p1, NULL,
				routine, head->linked_list) != 0)
			printf("Pthread Error\n");
		pthread_detach(head->linked_list->p1);
		head->linked_list = head->linked_list->next;
		if (head->linked_list == head->linked_list2)
			break ;
	}
	while (1)
	{
		pthread_mutex_lock(&head->linked_list->msoos);
		if (in_time() - head->linked_list->ate > head->death)
		{
			kadir_chi_haja(head->linked_list, "died");
			return ;
		}
		pthread_mutex_unlock(&head->linked_list->msoos);
		head->linked_list = head->linked_list->next;
	}
}

int	main(int ac, char **av)
{
	t_list	head;
	int		i;
	int		purpose;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		if (one_two_three_four(av, 200) == 1 && \
			question_authority(av) == 1 && is_number(av))
		{
			purpose = ft_atoi(av[1]);
			head.death = ft_atoi(av[2]);
			head.eat = ft_atoi(av[3]);
			head.sleep = ft_atoi(av[4]);
			while (i <= purpose)
				ft_lstadd_back(&head.linked_list, lst_new(i++, &head));
			create_detach(&head);
		}
		else
			printf("Error\nNot Valid\n");
	}
	else
		printf("Error\nNot Valid\n");
}
