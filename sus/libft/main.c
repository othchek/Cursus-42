#include <stdio.h>
#include "libft.h"

int main()
{
    char myName[] = "papay";
    char random[] = "--+152";
    char random1[] = "-16";
    printf(">> The begining of ft_atoi main >>\n");
    printf(">>>> First test : %d\tSecond test : %d >>>>\n", ft_atoi(random), ft_atoi(random1));
    printf(">> The end of ft_atoi main >>\n");
    printf(">> The begining of ft_strrchr main >>\n");
    printf(">>>> First test : %s\tSecond test : %s >>>>\n", ft_strrchr(myName, 'p'), ft_strrchr(myName, 'a'));
    printf(">> The end of ft_strrchr main >>\n");
}