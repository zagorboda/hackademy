#include <stdio.h>

char *ft_memchr(const void *s, int c, int n)
{
    const char *t = s;

    if (c > 256)
    {
        c = c % 256;
    }

    for (int i = 0; i < n; i++)
    {
        if (t[i] == c)
        {
            return (char *)&t[i];
        }
    }

    return NULL;
}
