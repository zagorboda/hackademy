#include <stdio.h>

unsigned int my_strlen(char *str) 
{
    int str_len = 0;
    char next_char = *str;
    
    // Iterate over string and count iterations
    while (next_char != '\0')
    {
        str_len++;
        next_char = *++str;
    }

    return str_len;
}

