/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:59:57 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/09 15:03:36 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_push {
	int						data;
	struct s_push			*next;
	pthread_t				p1;
	pthread_mutex_t			mutex;
	long long				ate;
	struct s_push			*prev;
	struct s_list			*struct_ss;
}	t_push;

typedef struct s_list {
	long long	time;
	t_push		*linked_list;
	t_push		*linked_list2;
	int			philo;
	int			death;
	int			eat;
	int			sleep;
	int			tbd;
}	t_list;

int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		one_two_three_four(char **str, int num);
int		question_authority(char **str);
int		is_number(char **str);
void	ft_lstadd_back(t_push **lst, t_push *new);
t_push	*lst_new(int sata, t_list *linked_list);
void	usleeping(long long var);

#endif