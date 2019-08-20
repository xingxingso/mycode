#include <stdio.h> 
#include <stdarg.h> 
#include <stdlib.h>

// int vprintf( char *format, va_list arg_ptr );
// int vfprintf( FILE *stream, const char *format, va_list arg_ptr );
// int vsprintf( char *buffer, char *format, va_list arg_ptr );

/* error:  print an error message and die */ 
void error(char *fmt, ...) 
{ 
    va_list args; 

    va_start(args, fmt); 
    fprintf(stderr, "error: "); 
    vfprintf(stderr, fmt, args); 
    fprintf(stderr, "\n"); 
    va_end(args); 
    exit(1); 
}
