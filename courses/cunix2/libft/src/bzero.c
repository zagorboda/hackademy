#include <stdio.h>

void ft_bzero(char *s, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        s[i] = '\0';
    }

}
