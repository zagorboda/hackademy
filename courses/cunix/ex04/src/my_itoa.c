#include <stdio.h>
#include <stdlib.h>

char *my_itoa(int nmb)
{
    int digits = 0, temp = nmb, is_negative = 0;

    // Check sign
    if (temp < 0)
    {
        is_negative = 1;
    }

    // Count digits in number
    if (temp == 0)
    {
        digits = 1;
    }

    while (temp)
    {
        temp /= 10;
        digits += 1;
    }

    // Allocate memory for resulting string
    char *res = calloc((digits + 2 + is_negative), sizeof(char));
    char *first = res;
    
    // Fill resulting string
    temp = nmb;
    if (temp < 0)
    {
        temp *= -1;
        res[0] = '-';
    }

    for (int i = digits - 1 + is_negative; i >= 0 + is_negative; i--)
    {
        res[i] = temp % 10 + '0';
        temp /= 10;
    }

    res[digits + 1 + is_negative] = '\0';

    return first;
}
