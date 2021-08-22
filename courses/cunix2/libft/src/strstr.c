#include <stdio.h>
#include "../libft.h"

char *ft_strstr(const char *s, const char *sub)
{
    if (my_strlen(sub) == 0)
    {
        return (char *)&s[0];
    }

    for (int i = 0; s[i] != 0; i++)
    {
        for (int j = 0; sub[j] != 0; j++)
        {
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
