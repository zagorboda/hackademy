#include <stdio.h>
#include <stdlib.h>

char *ft_memmove(void *dest, const void *src, int n)
{
    char *temp = (char *) malloc(sizeof(char) * n);

    char *d = dest;
    const char *s = src;

    for (int i = 0; i < n; i++)
    {
        temp[i] = s[i];
    }

    for (int i = 0; i < n; i++)
    {
        d[i] = temp[i];
    }   

    free(temp);

    return dest;
}
