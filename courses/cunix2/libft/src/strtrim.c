#include <stdio.h>
#include <stdlib.h>

char * ft_strtrim(const char *s)
{
    int end;
    int i = 0, start=0;
    
    while (s[i] != 0){
        i++;
    }
    end = i;
    i=0;
    
    // Detect start and end indexes of new trimmed string
    while (s[i] != 0)
    {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'){
            if (i == 0)
            {
                start = 1;
            }
            else if (start == i)
            {
                start = i+1;
            }
            else 
            {
                if (end == 0)
                {
                    end = i;
                }
            }
        }
        else
        {
            end = 0;
        }
        i++;
    }

    if (end == 0)
    {
        end = i;
    }

    char *res = (char *) malloc((end - start + 1) * sizeof(char));
   
    if (res == NULL)
    {
        return NULL;
    }

    i = 0;
    for(i = 0; i < end - start; i++)
    {
        res[i] = s[start + i];
    }

    res[i] = '\0';
    return res;
 }
