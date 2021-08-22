#include <stdio.h>

char *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    char *d = dest;
    const char *s = src;

    for (size_t i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            d[i] = c;
            return &d[i + 1];
        }

        d[i] = s[i];
    }

    return NULL;
}

