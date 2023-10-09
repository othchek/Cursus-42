/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:52:54 by otchekai          #+#    #+#             */
/*   Updated: 2023/06/22 10:50:36 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	k;
	int	sign;

	i = 0;
	k = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + (str[i] - '0');
		i++;
	}
	return (k * sign);
}

void	ft_lstadd_back(t_push **lst, t_push *new)
{
	t_push	*nextlst;
	t_push	*head;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	nextlst = *lst;
	while (nextlst && nextlst->next != head)
		nextlst = nextlst->next;
	nextlst->next = new;
	new->next = head;
	new->prev = nextlst;
	head->prev = new;
}

t_push	*lst_new(int sata, t_list *linked_list)
{
	t_push	*node;

	node = malloc(sizeof(t_push));
	if (!node)
		return (NULL);
	pthread_mutex_init(&node->mutex, NULL);
	pthread_mutex_init(&node->death, NULL);
	pthread_mutex_init(&node->manger, NULL);
	node->data = sata;
	node->next = node;
	node->prev = node;
	node->struct_ss = linked_list;
	node->lasteat = 0;
	return (node);
}
