/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:39:50 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/05 21:27:20 by otchekai         ###   ########.fr       */
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

#endif