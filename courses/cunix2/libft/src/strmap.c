#include <stdio.h>
#include <stdlib.h>

char *ft_strmap(char const *s, char (*f)(char))
{
    int i = 0;
    while (s[i] != 0)
    {
        i++;
    }

    char *res = (char *) malloc((i + 1) * sizeof(char));
    
    for (i = 0; s[i] != 0; i++)
    {
        res[i] = f(s[i]);
    }

    res[i] = 0;
    return res;
}


