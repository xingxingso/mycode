/*
Here is the first solution by Flash Gordon, 
which uses pointers which have not been introduced by this point. 
It relies on the C99 behaviour of dividing a negative number rounding towards zero.
 */
char *itoa(int n, char s[], int base)
{
    int d = n % base;
    int r = n / base;
    if (n < 0) {
        *s++ = '-';
        d = -d;
        r = -r;
    }
    if (r)
        s = itoa(r, s, base);
    *s++ = "0123456789abcdefghijklmnopqrstuvwxyz"[d];
    *s = 0;
    return s;
}
