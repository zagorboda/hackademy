#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ft_strsplit(const char *s, char c)
{
    return NULL;

    int word_count = 0, i;

    for (i = 1; s[i] != '\0'; i++)
    {
        if (s[i] == c && s[i-1] != c)
        {
            word_count++;
        }
    }
    
    char **res = (char **)malloc(word_count * sizeof(char*));
    
    int size = 0, j=0, k=0, start=0;
    i = 0;
    while (s[i] != '\0')
    {   
        if (s[i] != c)
        {
            if (start == 0)
            {
                start = i;
            }
            size++;
        }
        else
        {
            char* word = (char*)malloc((size + 1)*sizeof(char));
            for (j = 0; j < size; j++)
            {
                word[j] = s[start + j];
            }
            word[j + 1] = '\0';
            res[k] = word;
            k++;
            size = 0;

            i = j-1;
        }
        i++;
    }

    return res;

}
