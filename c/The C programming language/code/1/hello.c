#include <stdio.h>

int main()
{
    // printf("hello, world\n");
    printf("hello, ");
    printf("world");
    printf("\n");

    printf("Audible or visual alert. \a\n");  
    printf("Form feed. \f\n");
    printf("This escape, \r, moves the active position to the initial position of the current line.\n");
    printf("Vertical tab \v is tricky, as its behaviour is unspecified under certain conditions.\n");

    //1.5.1
    printf("%d\n", getchar() != EOF);

    printf("%u\n", EOF);
}
