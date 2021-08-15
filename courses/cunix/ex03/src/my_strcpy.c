#include <stdio.h>

char *my_strcpy(char *dest, const char *src)
{
    char *first = dest;
    
    //Check empty string
    if (src[0] == '\0')
    {
        dest[0] = '\0';
        return first;
    }

    int i = 0; 
    // Iterate over source string and copy chars to destination
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    // Add null terminator
    dest[i] = '\0';
    
    // Return pointer to first char in destination string
    return first;
}

