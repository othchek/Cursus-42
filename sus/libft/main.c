/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:16:37 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/16 13:17:32 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main()
{
    char myName[] = "papay";
    char random[] = "papay";
    char random1[] = "papay";
    printf(">> The begining of ft_atoi main >>\n");
    printf(">>>> First test : %zu\tSecond test : %zu >>>>\n", ft_strlen(random), ft_strlen(random1));
    printf(">> The end of ft_atoi main >>\n");
    printf(">> The begining of ft_strrchr main >>\n");
    printf(">>>> First test : %s\tSecond test : %s >>>>\n", ft_strrchr(myName, 'p'), ft_strrchr(myName, 'a'));
    printf(">> The end of ft_strrchr main >>\n");
}