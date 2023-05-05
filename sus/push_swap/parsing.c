/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:41:51 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/04 23:58:35 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_valid(char **str)
{
	int		index;
	int		j;

	index = 0;
	while (str[index])
	{
		j = 0;
		if (str[index][j] == '-' && str[index][j + 1])
				j++;
		if (str[index][j] == '+' && str[index][j + 1])
				j++;
		while (str[index][j])
		{
			if (!ft_isdigit(str[index][j]) && str[index][j] != 32)
				ft_error("Error\nNot Valid");
			j++;
		}
		if (ft_strlen(str[index]) == 0)
			ft_error("Error\nNot Valid");
		ft_atoi(str[index]);
		index++;
	}
	return (0);
}

int	smoking_mirrors(char **str)
{
	int	index;
	int	num;

	num = 0;
	while (str[num])
	{
		index = num + 1;
		while (str[index])
		{
			if (ft_atoi(str[num]) == ft_atoi(str[index]))
				ft_error("Error\nDuplicated Number");
			index++;
		}
		num++;
	}
	return (0);
}

char	**kill_to_flourish(char **str)
{
	char	*s;
	char	**split;
	int		index;

	index = 1;
	s = NULL;
	if (!s)
		s = ft_strdup("");
	while (str[index])
	{
		s = ft_strjoin(s, str[index]);
		s = ft_strjoin(s, " ");
		index++;
	}
	split = ft_split(s, ' ');
	free(s);
	check_if_valid(split);
	smoking_mirrors(split);
	return (split);
}

int	max_or_min(char *str)
{
	char			*purpose;
	long long		result;

	purpose = str;
	result = ft_atoi(str);
	if (result < INT_MIN
		|| result > INT_MAX)
		ft_error("Error\nAbove the INT_MAX or Smaller than the INT_MIN");
	return (0);
}
