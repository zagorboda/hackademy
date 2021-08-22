#include <stdio.h>
#include <stdlib.h>
#include "my_strlen.h"

char *ft_strdup(const char *s)
{
    int s_len = my_strlen(s);
    char *new = (char *) malloc((s_len + 1) * sizeof(char));
    char *first = new;
    for (int i = 0; i < s_len; i++)
    {
        new[i] = s[i];
    }
    new[s_len] = '\0';

    return first;
}
