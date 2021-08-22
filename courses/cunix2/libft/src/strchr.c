#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
    if (c > 255)
    {
        return (char *)s;
    }

    while (*s != '\0')
    {
        if (*s == c)
        {
            return (char *) s;
        }

        s++;
    }

    if (c == '\0')
    {
        return (char *) s;
    }

    return NULL;
}

