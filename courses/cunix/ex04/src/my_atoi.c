#include <stdio.h>
//#include <math.h>

// Custom power function
int my_pow(int base, int power)
{   
    if (power == 0)
    {
        return 1;
    }

    int res = base;
    for (int i = 1; i < power; i++)
    {
        res *= base;
    }

    return res;
}

int my_atoi(const char *nptr)
{
    int digits = 0, is_negative = 0;
    int i;

    // Check minus sign
    if (nptr[0] == '-' && nptr[1] != '\0')
    {
        is_negative = 1;
    }

    // Count number of digits
    i = 0 + is_negative;
    while (nptr[i] != '\0')
    {
        // Count only first consecutive digits
        if (nptr[i] >= '0' && nptr[i] <= '9')
        {
            digits++;
        } 
        else
        {
            break;
        }

        i++;
    }
    
    // Multiply every digit to 10 in power of digit position and add it to res
    int res = 0;
    for (i = 0; i < digits; i++)
    {
        res += (nptr[i + is_negative] - '0') * my_pow(10, digits - i - 1);
    }
    
    // Convert to negative if needed
    if (is_negative == 1)
    {
        res *= -1;
    }

    return res;
}
