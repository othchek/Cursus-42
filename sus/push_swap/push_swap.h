/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:39:50 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/14 11:56:26 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_push {
	int				data;
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
void	inst_ss(t_push **lst, t_push **lst1 , int i);
void	inst_rra(t_push **lst, int i);
void	inst_rrb(t_push **lst, int i);
void	inst_pa(t_push **heada, t_push **headb, int i);

#endif