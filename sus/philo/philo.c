/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:00:02 by otchekai          #+#    #+#             */
/*   Updated: 2023/06/22 15:02:02 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	can_trees_feel_pain(t_push *node, char *str)
{
	pthread_mutex_lock(&node->struct_ss->danger);
	if (ft_strncmp(str, "died", 4) == 0)
		printf("%lld %d %s 💀\n",
			(in_time() - node->struct_ss->time), node->data, str);
	else if (ft_strncmp(str, "died", 4) != 0)
	{
		printf("%lld %d %s 🤓\n",
			(in_time() - node->struct_ss->time), node->data, str);
		pthread_mutex_unlock(&node->struct_ss->danger);
	}
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
		can_trees_feel_pain(node, "has taken a fork");
		pthread_mutex_lock(&node->next->mutex);
		can_trees_feel_pain(node, "has taken a fork");
		pthread_mutex_lock(&node->death);
		can_trees_feel_pain(node, "is eating");
		node->ate = in_time();
		pthread_mutex_unlock(&node->death);
		pthread_mutex_lock(&node->struct_ss->eat_mutex);
		node->lasteat++;
		pthread_mutex_unlock(&node->struct_ss->eat_mutex);
		u_sleep(node->struct_ss->eat);
		pthread_mutex_unlock(&node->mutex);
		pthread_mutex_unlock(&node->next->mutex);
		can_trees_feel_pain(node, "is sleeping");
		u_sleep(node->struct_ss->sleep);
		can_trees_feel_pain(node, "is thinking");
	}
}

int	jesus_manger(t_push *node)
{
	t_push	*head;
	int		i;

	head = node;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&node->struct_ss->eat_mutex);
		if (head->lasteat >= head->struct_ss->tbd)
			i++;
		head = head->next;
		pthread_mutex_unlock(&node->struct_ss->eat_mutex);
		if (head == node)
			break ;
	}
	return (i);
}

void	patience_is_bitter_but_its_fruit_is_sweet(t_list *head)
{
	int		i;
	t_push	*tmp;

	tmp = head->linked_list;
	i = 0;
	head->time = in_time();
	pthread_mutex_init(&head->eat_mutex, NULL);
	pthread_mutex_init(&head->danger, NULL);
	while (1)
	{
		head->linked_list->ate = in_time();
		if (pthread_create(&head->linked_list->p1, NULL,
				routine, head->linked_list) != 0)
			printf("Pthread Error\n");
		pthread_detach(head->linked_list->p1);
		head->linked_list = head->linked_list->next;
		if (head->linked_list == tmp)
			break ;
	}
	pleased_to_die(head);
}

int	main(int ac, char **av)
{
	t_list	head;
	int		i;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		if (one_two_three_four(av, 200) == 1 && \
			question_authority(av) == 1 && is_number(av))
		{
			head.tbd = INT_MAX;
			head.philo = ft_atoi(av[1]);
			head.death = ft_atoi(av[2]);
			head.eat = ft_atoi(av[3]);
			head.sleep = ft_atoi(av[4]);
			if (av[5])
				head.tbd = ft_atoi(av[5]);
			head.linked_list = NULL;
			while (i <= head.philo)
				ft_lstadd_back(&head.linked_list, lst_new(i++, &head));
			patience_is_bitter_but_its_fruit_is_sweet(&head);
			pthread_mutex_destroy(&head.danger);
			pthread_mutex_destroy(&head.eat_mutex);
		}
		else
			printf("Error\nNot Valid\n");
	}
	else
		printf("Error\nNot Valid\n");
}
