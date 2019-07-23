/**
 * Write a program to print a histogram of the frequencies 
 * of different characters in its input.
 */

#include <stdio.h>

#define MAX 100
#define EXIST 1
#define NOEXIST 0

int main(void)
{
    int c, i, get, height, j;
    int types[MAX-1];
    int typesNums[MAX-1];

    height = 1;
    for (i = 0; i < MAX; ++i) {
        types[i] = EOF;
        typesNums[i] = NOEXIST;
    }

    while((c = getchar()) != EOF) {
        get = NOEXIST;
        for (i = 0; i < MAX; ++i) {
            if (get == NOEXIST && types[i] == EOF) {
                types[i] = c;
                ++typesNums[i];
                get = EXIST;
            } else if ( get == NOEXIST && types[i] == c) {
                get = EXIST;
                ++typesNums[i];

                if(typesNums[i] > height)
                    height = typesNums[i];
            }
        }
    }

    // print
    for (i = height; i > 0; --i) {
        printf("%3d|", i);
        for (j = 0; j < MAX; ++j) {
            if (typesNums[j] != NOEXIST) {
                if (typesNums[j] >= i)
                    printf("   *");
                else
                    printf("    ");
            }
        }
        printf("\n");
    }

    printf("   +");
    for (i = 0; i < MAX; ++i)
    {
        if (typesNums[i] != NOEXIST)
            printf("----");
    }
    printf("\n");

    printf("    ");
    for (i = 0; i < MAX; ++i)
    {
        if (types[i] != EOF) {
            printf("   %c", types[i]);   
            // printf("   ");   
            // putchar(types[i]);
        }
    }

    return 0;
}
