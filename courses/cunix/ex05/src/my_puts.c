#include <stdio.h>

int my_puts(const char *s)
{
    const char *next_char = s;
    // Put next char while there is one
    while (*next_char)
    {
        putchar(*next_char);
        next_char++;
    }
    
    // Add newline char
    putchar('\n');

    return 0;
}
