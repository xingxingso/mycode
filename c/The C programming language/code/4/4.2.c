/******************************************************
"Extend atof to handle scientific notation of 
the form 123.45e-6 where a floating-point number 
may be followed by e or E and an optionally signed exponent."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    double val, atof(char s[]);
    char s[] = "-123.45E-6";

    val = atof(s);

    printf("%f\n", val);

    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, sign2;
    int i, sign, e;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    
    if (s[i] == 'e' || s[i] == 'E')
    {
        sign2 = s[++i] == '-' ? -1 : 1;

        if (s[i] == '-')
        {
            ++i;
        }
        
        for (e=0; isdigit(s[i]); i++)
            e = 10*e + (s[i] - '0');

        for (; e > 0; --e)
        {
            if (sign2 == -1) {
                power *= 10;
            }
            else {
                power /= 10;
            }
        }
        
    }

    return sign * val / power;
}

/* atof: convert string s to double */
// double atof(char s[])
// {
//     double val, power;
//     int i, sign;
//     for (i = 0; isspace(s[i]); i++) /* skip white space */
//         ;
//     sign = (s[i] == '-') ? -1 : 1;
//     if (s[i] == '+' || s[i] == '-')
//         i++;
//     for (val = 0.0; isdigit(s[i]); i++)
//         val = 10.0 * val + (s[i] - '0');
//     if (s[i] == '.')
//         i++;
//     for (power = 1.0; isdigit(s[i]); i++) {
//         val = 10.0 * val + (s[i] - '0');
//         power *= 10;
//     }
//     return sign * val / power;
// }
