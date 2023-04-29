/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:33:38 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 16:07:55 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	give_me_inst(char *str, t_push **heada, t_push **headb)
{
	if (!strncmp(str, "rra", 3))
		inst_rra(heada, 0);
	else if (!strncmp(str, "rrb", 3))
		inst_rrb(headb, 0);
	else if (!strncmp(str, "rrr", 3))
		inst_rrr(heada, headb, 0);
	else if (!strncmp(str, "ra", 2))
		inst_ra(heada, 0);
	else if (!strncmp(str, "rb", 2))
		inst_rb(headb, 0);
	else if (!strncmp(str, "rr", 2))
		inst_rr(heada, headb, 0);
	else if (!strncmp(str, "sa", 2))
		inst_sa(heada, 0);
	else if (!strncmp(str, "sb", 2))
		inst_sb(headb, 0);
	else if (!strncmp(str, "ss", 2))
		inst_ss(heada, headb, 0);
	else if (!strncmp(str, "pa", 2))
		inst_pa(heada, headb, 0);
	else if (!strncmp(str, "pb", 2))
		inst_pb(heada, headb, 0);
	else
		ft_error("Error");
}

int	main(int ac, char **av)
{
	int		i;
	char	**split;
    char    *ptr;
	t_push	*heada;
	t_push	*headb;

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
        ptr = get_next_line(0);
        while (ptr)
        {
            give_me_inst(ptr, &heada, &headb);
            free(ptr);
            ptr = get_next_line(0);
        }
		if (!is_sorted(&heada) || (headb != NULL))
			ft_error("KO");
		else
			ft_error("OK");
	}
	else
		ft_error("Error\nArgument Error!");
}
