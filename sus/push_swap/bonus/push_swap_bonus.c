/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:33:38 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/04 22:50:45 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	give_me_inst(char *str, t_push **heada, t_push **headb, t_print **headc)
{
	if (!strncmp(str, "rra\n", 4))
		inst_rra(heada, headc, 0);
	else if (!strncmp(str, "rrb\n", 4))
		inst_rrb(headb, headc, 0);
	else if (!strncmp(str, "rrr\n", 4))
		inst_rrr(heada, headb, headc, 0);
	else if (!strncmp(str, "ra\n", 3))
		inst_ra(heada, headc, 0);
	else if (!strncmp(str, "rb\n", 3))
		inst_rb(headb, headc, 0);
	else if (!strncmp(str, "rr\n", 3))
		inst_rr(heada, headb, headc, 0);
	else if (!strncmp(str, "sa\n", 3))
		inst_sa(heada, headc, 0);
	else if (!strncmp(str, "sb\n", 3))
		inst_sb(headb, headc, 0);
	else if (!strncmp(str, "ss\n", 3))
		inst_ss(heada, headb, headc, 0);
	else if (!strncmp(str, "pa\n", 3))
		inst_pa(heada, headb, headc, 0);
	else if (!strncmp(str, "pb\n", 3))
		inst_pb(heada, headb, headc, 0);
	else
		ft_error("Error");
}

void	norminette(t_push **heada, t_push **headb, t_print **headc)
{
	char	*ptr;

	ptr = get_next_line(0);
	while (ptr)
	{
		give_me_inst(ptr, heada, headb, headc);
		free(ptr);
		ptr = get_next_line(0);
	}
}

void	norminette2(t_push *heada, t_push *headb)
{
	if (!is_sorted(&heada) || (headb != NULL))
		ft_error("KO");
	else
		return (ft_putstr_fd("OK\n", 2), ft_lstclear(&heada));
}

int	main(int ac, char **av)
{
	int		i;
	char	**split;
	t_push	*heada;
	t_push	*headb;
	t_print	*headc;

	i = 1;
	heada = NULL;
	headb = NULL;
	if (ac > 1)
	{
		while (av[i])
			max_or_min(av[i++]);
		split = kill_to_flourish(av);
		i = 0;
		while (split[i])
			ft_lstadd_back(&heada, lst_new(ft_atoi(split[i++])));
		norminette(&heada, &headb, &headc);
		norminette2(heada, headb);
		allfree(split);
	}
	else
		exit(1);
}
