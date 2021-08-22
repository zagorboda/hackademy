#include <stdio.h> 
#include <stdarg.h>						
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

void ft_printf(char *,...);
void write_integer(int c);
void write_string(char *s);
int my_pow(int base, int c);
int read_integer_from_string(char *s);
int get_integer_len(int c);
void print_chars(char c, int t);

//int main() 
//{
//	ft_printf("TEST: |%d| |%c| |%s| |%+d| |% d| |%06d| |%-4d| \n", -1, 105, "ABC", 12, -12, -678, 184);
//	
//	return 0;
//} 

void ft_printf(char* format,...) 
{ 
	int i = 0;
	char val; 
	char *s, *s_tmp;
    int integer, i_tmp, i_tmp2;
	
	va_list arg; 
	va_start(arg, format); 

    while (format[i] != '\0')
	{
        while (format[i] != '%')
        {
            if (format[i] == '\0')
            {
                write(1, "\0", sizeof(char));
                break;
            }
            write(1, &format[i], sizeof(char));
            i++;
        }

        i++;

		switch(format[i]) 
		{
            case '%':
                write(1, &"%", sizeof(char));
                break;
			case 'c' : 
                val = va_arg(arg, int);
                s = &val;
				write(1, s, sizeof(char));
				break; 
            case 'i':			
			case 'd' :
                integer = va_arg(arg, int);
                write_integer(integer);
				break; 
						
			case 's': 
                s = va_arg(arg, char *);
                write_string(s);
			  	break;
            case '+':
                if ((format[i+1] != '\0') && (format[i+1] == 'd' || format[i+1] == 'i'))
                {
                    integer = va_arg(arg, int);
                    if (integer > 0)
                    {
                        write(1, &"+", sizeof(char));
                    }
                    write_integer(integer);
                    i++;
                }
                break;
            case ' ':
                integer = va_arg(arg, int);
                if (integer > 0)
                {
                    write(1, &" ", sizeof(char));
                }
                write_integer(integer);
                i++;
                break;
            case '0':
                integer = va_arg(arg, int);

                s_tmp = &format[i];
                i_tmp = read_integer_from_string(s_tmp);
                i_tmp2 = get_integer_len(integer);
                if (i_tmp2 > i_tmp)
                {
                    write_integer(integer);
                } 
                else
                {
                    i_tmp -= i_tmp2;
                    if (integer < 0)
                    {
                        write(1, &"-", sizeof(char));
                        integer = -integer;
                        i_tmp--;
                    }
                    print_chars('0', i_tmp);
                    write_integer(integer);
                }

                i += 2;
                break;
            case '-':
                integer = va_arg(arg, int);
                
                s_tmp = &format[i+1];
                i_tmp = read_integer_from_string(s_tmp);
                i_tmp2 = get_integer_len(integer);
                write_integer(integer);
                if (i_tmp2 < i_tmp)
                {
                    i_tmp -= i_tmp2;
                    if (integer < 0)
                    {
                        i_tmp--;
                    }
                    print_chars(' ', i_tmp);
                }
                
                i += 2;
                break;
            default:
                if (format[i-1] == '%')
                {
                    write(1, "%", sizeof(char));
                }
                //write(1, &"%", sizeof(char));
                //write(1, &format[i], sizeof(char));
		}
        i++;
	} 
	
	va_end(arg); 
}

int my_pow(int base, int power)
{
    int res = base;
    if (power == 0)
        return 1;

    while (power > 1)
    {
        res = res * base;
        power--;
    }

    return res;

}

void write_integer(int c){
    int temp, count = 0;
    int next_digit;
    char t;
    if (c == 0)
    {
        write(1, &"0", sizeof(char));
    }
    if (c < 0)
    {
        c = -1 * c;
        write(1, &"-", sizeof(char));
    }
    temp = c;

    while (temp >= 1)
    {  
        temp = temp / 10;
        count++;
    }
    //if (c < 10)
    //{
    //    t = c + '0';
    //    write(1, &t, sizeof(char));
    //}
    while (c >= 1)
    {
        next_digit = (int)(c / (my_pow(10, count-1)));
        t = next_digit + '0';
        write(1, &t, sizeof(char));
        c = c - next_digit*my_pow(10, count-1);
        count--;
    }
}

void write_string(char *s)
{
    int i=0;
    while (s[i] != '\0')
    {
        write(1, &s[i], sizeof(char));
        i++;
    }
}

int get_integer_len(int c)
{
    int count = 0;
    if (c < 0)
    {
        c = -c;
    }
    while (c >= 1)
    {  
        c = c / 10;
        count++;
    }

    return count;
}

int read_integer_from_string(char *s)
{
    int res = 0, j = 0, i = 0;
    for  (; s[i] >= '0' && s[i] <= '9'; i++)
    {}
    i--;
    
    for (j = 0; j <= i; j++)
    {
        res += (s[j] - '0') * my_pow(10, i - j);
    }

    return res;

}

void print_chars(char c, int t)
{
    for (int i = 0; i < t; i++)
    {
        write(1, &c, sizeof(char));
    }
}   

