/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:39:50 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/03 01:14:17 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"
# include "get_next_line.h"

typedef struct s_push {
	int				data;
	int				index;
	struct s_push	*next;
	struct s_push	*prev;
}	t_push;

int		check_if_valid(char **str);
int		smoking_mirrors(char **str);
int		max_or_min(char *str);
t_push	*lst_new(int sata);
char	**kill_to_flourish(char **str);
void	ft_lstadd_back(t_push **lst, t_push *new);
void	ft_lstadd_front(t_push **lst, t_push *new);
int		ft_lstsize(t_push *lst);
void	inst_sb(t_push **lst, int i);
void	inst_sa(t_push **lst, int i);
void	inst_ra(t_push **lst, int i);
void	inst_rb(t_push **lst, int i);
void	inst_rr(t_push **heada, t_push **headb, int i);
void	inst_ss(t_push **heada, t_push **headb, int i);
void	inst_rra(t_push **lst, int i);
void	inst_rrb(t_push **lst, int i);
void	inst_rrr(t_push **heada, t_push **headb, int i);
void	inst_pa(t_push **stack_a, t_push **stack_b, int i);
void	inst_pb(t_push **stack_a, t_push **stack_b, int i);
void	cookielolxx(t_push **lst_a);
void	three_numbers(t_push **Morow);
void	flower_in_the_dawn(t_push **heada, t_push **headb);
void	sort_stack(t_push **heada, t_push **headb);
void	reformed_five(t_push **heada, t_push **headb);
void	pd(t_push **heada, t_push **headb);
void	khundred_numbers(t_push **heada, t_push **headb, int size);
void	five_khundred_numbers(t_push **heada, t_push **headb, int size);
void	ft_lstclear(t_push **lst);
void	push_it_back(t_push **heada, t_push **headb);
void	find_the_chonk(t_push **Morow, int *max, int *second_max);
void	sort_big(t_push **heada, t_push **headb);
int		max(t_push **headb, int half, int index);
void	allfree(char **str);
int		is_sorted(t_push **lst);

#endif