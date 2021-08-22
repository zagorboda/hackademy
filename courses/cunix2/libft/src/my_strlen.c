#include <stdio.h>
#include "my_strlen.h"
#include <string.h>

int my_strlen(const char *str) 
{
    int str_len = 0;
    const char *t = str;

    // Iterate over string and count iterations
    while (*str != '\0')
    {
        str_len++;
        str++;
    }

    str = t;
    return str_len;
}

