/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:00:02 by otchekai          #+#    #+#             */
/*   Updated: 2023/06/18 02:00:27 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	in_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	can_trees_feel_pain(t_push *node, char *str)
{
	if (ft_strncmp(str, "died", 4) == 0)
		printf("%lld %d %s💀\n",
			(in_time() - node->struct_ss->time), node->data, str);
	else
		printf("%lld %d %s 🤓\n",
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
		can_trees_feel_pain(node, "has taken a fork");
		pthread_mutex_lock(&node->next->mutex);
		can_trees_feel_pain(node, "has taken a fork");
		pthread_mutex_lock(&node->death);
		node->ate = in_time();
		node->lasteat++;
		can_trees_feel_pain(node, "is eating");
		pthread_mutex_unlock(&node->death);
		u_sleep(node->struct_ss->eat);
		pthread_mutex_unlock(&node->mutex);
		pthread_mutex_unlock(&node->next->mutex);
		can_trees_feel_pain(node, "is sleeping");
		u_sleep(node->struct_ss->sleep);
		can_trees_feel_pain(node, "is thinking");
	}
	return (0);
}

int	jesus_manger(t_push *node)
{
	t_push	*head;

	head = node;
	while (1)
	{
		if (head->struct_ss->tbd)
		{
			if (head->lasteat >= head->struct_ss->tbd * head->struct_ss->philo)
				return (0);
		}
	}
}

void	patience_is_bitter_but_its_fruit_is_sweet(t_list *head)
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

int	main(int ac, char **av)
{
	t_list	head;
	int		i;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		system("open philo.jpg");
		if (one_two_three_four(av, 200) == 1 && \
			question_authority(av) == 1 && is_number(av))
		{
			head.philo = ft_atoi(av[1]);
			head.death = ft_atoi(av[2]);
			head.eat = ft_atoi(av[3]);
			head.sleep = ft_atoi(av[4]);
			if (av[5])
				head.tbd = ft_atoi(av[5]);
			while (i <= head.philo)
				ft_lstadd_back(&head.linked_list, lst_new(i++, &head));
			patience_is_bitter_but_its_fruit_is_sweet(&head);
		}
		else
			printf("Error\nNot Valid\n");
	}
	else
		printf("Error\nNot Valid\n");
}
