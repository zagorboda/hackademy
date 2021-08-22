#include <stdio.h>

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i = 0;
    // While there are next chars in both s    trings, iterate and compare
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (i == n)
        {
            return 0;
        }
        if (str1[i] == str2[i])
        {
            i++;
            continue;
        }

        if (str1[i] > str2[i])
        {
            return 1;
        }

        if (str1[i] < str2[i])
        {
            return -1;
        }

        i++;
    }

    if (i == n)
    {
        return 0;
    }

    // If at least one of the strings ends, check both for null terminator
    if (str1[i] == '\0' && str2[i] ==     '\0')
    {
        return 0;
    }

    if (str1[i] != '\0')
    {
        return 1;
    }

    if (str2[i] != '\0')
    {
        return -1;
    }

    return 0;
}

