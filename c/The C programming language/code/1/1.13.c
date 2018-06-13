#include <stdio.h>

int main(void)
{
    int length, c, i, j;
    int ndigit[11];
    length = 0;

    for (i = 0; i < 11; ++i)
        ndigit[i] = 0;
    

    while((c=getchar()) != EOF) 
    {
        if(c != ' ' && c != '\t' && c != '\n') {
            ++length;
        } else if(length > 0 && length <= 10){
            ++ndigit[length-1];
            length = 0; 
        }else if(length > 10){
            ++ndigit[10];
            length = 0;
        }
    }

    printf("\n\n");
    // horizontal
    for (i = 0; i < 11; ++i)
    {
        if (i < 10)
            printf("%3d|", i+1);
        else
            printf(">10|");

        for(j = 0; j < ndigit[i]; ++j)
            putchar('*');

        printf("\n");
    }

    // histogram
    /*int max = 0;
    for (i = 0; i < 11; ++i)
    {
        if (max < ndigit[i])
            max = ndigit[i];
    }

    for (i = max; i >= 0; --i) {
        if (i == 0)
            printf("   +");   
        else
            printf("%3d|", i);

        for (int j = 0; j < 11; ++j)
        {
            if (i == 0)
                printf("----");
            else if (ndigit[j] >= i)
                printf("  *|");
            else
                printf("   |");
        }

        printf("\n");
    }

    printf("    ");

    for (i = 0; i < 11; ++i)
    {
        if (i < 10) {
            printf("%3d|", i+1);
        } else {
            printf(" >10");
        }
    }*/

    printf("\n\n");
    // histogram 2
    int max = 0;
    for (i = 0; i < 11; ++i)
    {
        if (max < ndigit[i])
            max = ndigit[i];
    }

    for (i = max; i >= 0; --i) {
        if (i == 0)
            printf("   +");   
        else
            printf("%3d|", i);

        for (int j = 0; j < 11; ++j)
        {
            if (i == 0)
                printf("----");
            else if (ndigit[j] == i)
                if (j < 10 && ndigit[j+1] > i)
                    printf("---|");
                else 
                    printf("----");
            else if (ndigit[j] > i || (j < 10 && ndigit[j+1] > i))
                printf("   |");
            else
                printf("    ");
        }

        printf("\n");
    }

    printf("    ");

    for (i = 0; i < 11; ++i)
    {
        if (i < 10) {
            printf("%3d|", i+1);
        } else {
            printf(" >10");
        }
    }


    return 0;
}
