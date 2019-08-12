int mygetline(char s[], int lim) 
{
    int c, i; 

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
        s[i] = c; 
    if (c == '\n') { 
        s[i] = c;
        ++i; 
    } 
    s[i] = '\0'; 
    return i; 
} 

/* getline:  read a line, return length */ 
// int getline(char *line, int max) 
// { 
//     if (fgets(line, max, stdin) == NULL) 
//         return 0; 
//     else 
//         return strlen(line); 
// } 
