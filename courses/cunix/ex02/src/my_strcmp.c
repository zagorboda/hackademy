#include <stdio.h>

int my_strcmp(char *str1, char *str2)
{
    int i = 0;
    // While there are next chars in both strings, iterate and compare
    while (str1[i] != '\0' && str2[i] != '\0')
    {
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

    // If at least one of the strings ends, check both for null terminator
    if (str1[i] == '\0' && str2[i] == '\0')
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

