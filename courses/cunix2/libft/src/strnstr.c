#include <stdio.h>
#include "../libft.h"

char *ft_strnstr(const char *s, const char *sub, size_t n)
{
    if (my_strlen(sub) == 0)
    {
        return (char *)&s[0];
    }

    for (size_t i = 0; s[i] != 0; i++)
    { 
        for (size_t j = 0; sub[j] != 0; j++)
        {
            if (i + j == n)
            {
                return NULL;
            }

            if (s[i + j] != sub[j])
            {
                break;
            }

            if (sub[j + 1] == 0)
            {
                return (char *)&s[i];
            }
        }
    }

    return NULL;
}

