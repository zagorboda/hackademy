#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, int n)
{
    const unsigned char *t1 = s1;
    const unsigned char *t2 = s2;

    for (int i = 0; i < n; i++)
    {
        if (t1[i] > t2[i])
        {
            return 1;
        }
        if (t1[i] < t2[i])
        {
            return -1;
        }
    }

    return 0;
}
