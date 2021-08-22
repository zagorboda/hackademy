#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{

    return NULL;



    size_t s_len = 0;
    while (s[s_len] != 0)
    {
        s_len++;
    }
    if (start > s_len)
    {
        return NULL;
    }

    char *res = (char *) malloc((len + 1) * sizeof(char));

    size_t i;

    if (res == NULL)
    {
        return NULL;
    }

    for (i = 0; i < len; i++)
    {
        res[i] = s[start + i];
    }
    res[i] = '\0';
    return res;
}
