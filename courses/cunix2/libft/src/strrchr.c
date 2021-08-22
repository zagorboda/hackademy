#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
    if (c > 255)
    {
        return (char *)s;
    }

    char *last = NULL;
    while (*s != '\0')
    {
        if (*s == c)
        {
            last = (char *)s;
        }

        s++;
    }

    if (c == '\0')
    {
        return (char *) s;
    }
    
    return (char *)last;
}
