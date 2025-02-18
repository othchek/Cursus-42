/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:39:50 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/05 00:38:09 by otchekai         ###   ########.fr       */
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
	int				indexing;
	struct s_push	*next;
	struct s_push	*prev;
}	t_push;

typedef struct s_print {
	char			*data;
	struct s_print	*next;
}	t_print;

typedef struct s_list {
	char	**split;
	int		i;
}	t_list;

int		check_if_valid(char **str);
int		smoking_mirrors(char **str);
int		max_or_min(char *str);
t_push	*lst_new(int sata);
char	**kill_to_flourish(char **str);
void	ft_lstadd_back(t_push **lst, t_push *new);
void	ft_lstadd_front(t_push **lst, t_push *new);
int		ft_lstsize(t_push *lst);
void	inst_sb(t_push **lst, t_print **headc, int i);
void	inst_sa(t_push **lst, t_print **headc, int i);
void	inst_ra(t_push **lst, t_print **headc, int i);
void	inst_rb(t_push **lst, t_print **headc, int i);
void	inst_rr(t_push **heada, t_push **headb, t_print **headc, int i);
void	inst_ss(t_push **heada, t_push **headb, t_print **headc, int i);
void	inst_rra(t_push **lst, t_print **headc, int i);
void	inst_rrb(t_push **lst, t_print **headc, int i);
void	inst_rrr(t_push **heada, t_push **headb, t_print **headc, int i);
void	inst_pa(t_push **stack_a, t_push **stack_b, t_print **headc, int i);
void	inst_pb(t_push **stack_a, t_push **stack_b, t_print **headc, int i);
void	cookielolxx(t_push **lst_a);
void	three_numbers(t_push **Morow, t_print **headc);
void	flower_in_the_dawn(t_push **heada, t_push **headb, t_print **headc);
void	sort_stack(t_push **heada, t_push **headb, t_print **headc);
void	reformed_five(t_push **heada, t_push **headb, t_print **headc);
void	pd(t_push **heada, t_push **headb, t_print **headc);
void	khundred_numbers(t_push **heada, t_push **headb,
			t_print **headc, int size);
void	five_khundred_numbers(t_push **heada, t_push **headb,
			t_print **headc, int size);
void	ft_lstclear(t_push **lst);
void	push_it_back(t_push **heada, t_push **headb, t_print **headc);
int		max(t_push **lst_b, int half_chunk, int index);
void	sort_big(t_push **heada, t_push **headb, t_print **headc);
void	allfree(char **str);
int		is_sorted(t_push **lst);
t_print	*lst_new2(char *sata);
void	ft_lstadd_back2(t_print **lst, t_print *new);
int		ft_index(t_push **Morow);
void	ft_clear_lst(t_print **lst);
void	normanitte(t_print *print, t_print *print2);

#endif