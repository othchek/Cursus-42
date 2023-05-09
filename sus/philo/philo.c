/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:00:02 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/09 15:13:42 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	in_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	kadir_chi_haja(t_push *node, char *str)
{
	printf("%lld %d %s\n", (in_time() - node->struct_ss->time), node->data, str);
}

void	*routine(void *ptr)
{
	t_push		*node;

	node = (t_push *) ptr;
	while (1)
	{
		pthread_mutex_lock(&node->mutex);
		kadir_chi_haja(node, "has taken a fork");
		pthread_mutex_lock(&node->next->mutex);
		kadir_chi_haja(node, "has taken a fork");
		node->ate = in_time();
		kadir_chi_haja(node, "is eating");
		usleep(node->struct_ss->eat * 1000);
		pthread_mutex_unlock(&node->mutex);
		pthread_mutex_unlock(&node->next->mutex);
		kadir_chi_haja(node, "is sleeping");
		usleep(node->struct_ss->eat * 1000);
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
		if (pthread_create(&head->linked_list->p1, NULL, routine, head->linked_list) != 0)
			printf("Pthread Error\n");
		pthread_detach(head->linked_list->p1);
		head->linked_list = head->linked_list->next;
		if (head->linked_list == head->linked_list2)
			break ;
	}
	while(1)
	{
		if (in_time() - head->linked_list->ate > head->death)
		{
			kadir_chi_haja(head->linked_list, "is dead");
			exit(0);
		}
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
			pthread_mutex_init(&head.linked_list->mutex, NULL);
			create_detach(&head);
		}
		else
			printf("Error\nNot Valid\n");
	}
	else
		printf("Error\nNot Valid\n");
}
