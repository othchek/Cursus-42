/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_all_you_need.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:53:35 by otchekai          #+#    #+#             */
/*   Updated: 2023/06/20 23:06:52 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_two_three_four(char **str, int num)
{
	int	index;

	index = 1;
	while (str[1])
	{
		if (ft_atoi(str[1]) >= index && ft_atoi(str[1]) <= num)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	question_authority(char **str)
{
	int	index;
	int	j;

	index = 2;
	j = 0;
	while (index < 5 && str[index])
	{
		if (ft_atoi(str[index]) >= 60)
			index++;
		else
			return (0);
	}
	return (1);
}

int	is_number(char **str)
{
	int	index;
	int	j;

	index = 1;
	while (str[index])
	{
		j = 0;
		while (str[index][j])
		{
			if (!ft_isdigit(str[index][j]))
				return (0);
			else
				return (1);
			j++;
		}
		index++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] > s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	u_sleep(long long value)
{
	long long var;

	var = in_time();
	while (in_time() < var + value)
		usleep(10);
}
