#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(const char *s1, const char *s2)
{

    int len1 = 0, len2 = 0;
    while (s1[len1] != 0)
    {
        len1++;
    }
    while (s2[len2] != 0)
    {
        len2++;
    }

    char *res = (char *) malloc((len1 + len2 + 1) * sizeof(char));
    int i;
    for (i = 0; i < len1; i++)
    {
        res[i] = s1[i];
    }
    for (i = 0; i < len2; i++)
    {
        res[len1 + i] = s2[i];
    }

    res[len1 + len2] = 0;

    return res;

}
