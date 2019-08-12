/******************************************************
"Write a program to compare two files, printing the first line where they differ."

Author: Kant Chan (1126973789@qq.com) 
******************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
    char line1[MAXLINE];
    char line2[MAXLINE];
    int nums=0;
    FILE *fp1;
    FILE *fp2;

    if (argc < 3) {
        printf("%s\n", "please input two files name");
        return 1;
    }

    fp1 = fopen(argv[1], "r");
    if (!fp1){
        printf("can't find file %s\n", argv[1]);
        return 1;
    }
    fp2 = fopen(argv[2], "r");
    if (!fp2){
        printf("can't find file %s\n", argv[2]);
        return 1;
    }
    while (fgets(line1, MAXLINE, fp1)!=NULL && fgets(line2, MAXLINE, fp2)!=NULL){
        ++nums;
        if (strcmp(line1, line2) !=0) {
            printf("in line: %d,\n1:%s\n2:%s\n", nums, line1, line2);
            return 0;
        }
    }

    return 0;
}
