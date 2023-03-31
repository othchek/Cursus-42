#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		kill_to_flourish(av);
		while (av[i])
			max_or_min(av[i++]);
	}
	else
		ft_error("Error\nArgument Error!");
}
