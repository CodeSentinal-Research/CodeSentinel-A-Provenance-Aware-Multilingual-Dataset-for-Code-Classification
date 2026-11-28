#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int parse_int(const char *s, int *out)
{
    errno = 0;
    char *end;
    long v = strtol(s, &end, 10);
    
    if (end == s)
    {
        fprintf(stderr, "ERROR: No digits - %s\n", s);
        return 1;
    }
    if (*end != '\0') 
    {
        fprintf(stderr, "ERROR: trailing junk - %s\n", s);
        return 1;
    }
    if (errno == ERANGE)
    {
        fprintf(stderr, "ERROR: overflow - %s\n", s);
        return 1;
    }
    if (v > INT_MAX || v < INT_MIN)
    {
        fprintf(stderr, "ERROR: integer does not fit in range - %s\n", s);
        return 1;
    }

    *out = v;
    return 0;
}

static int add_checked(int a, int b, int *out)
{
    if (b > 0 && a > INT_MAX - b)
    {
        return EXIT_FAILURE;
    }
    if (b < 0 && a < INT_MIN - b)
    {
        return EXIT_FAILURE;
    }
    *out = a + b;
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <n1> [n2] [n3] ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sum = 0;
    int a;
    for(int i=1; i<argc; i++)
    {
        if(parse_int(argv[i], &a) !=0) return EXIT_FAILURE;
        if(add_checked(sum, a, &sum) !=0)
        {
            fprintf(stderr, "ERROR: sum overflow\n");
            return EXIT_FAILURE;
        }
    }
    
    printf("Total: %d\n", sum);
    return EXIT_SUCCESS;
}
