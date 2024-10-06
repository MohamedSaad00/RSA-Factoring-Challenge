#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - Finds two factors of a number and prints them
 * @n: The number to be factored
 */
void factorize(unsigned long long int n)
{
    unsigned long long int p, q;

    if (n % 2 == 0)
    {
        q = n / 2;
        printf("%llu=%llu*2\n", n, q);
        return;
    }

    for (p = 3; p * p <= n; p += 2)
    {
        if (n % p == 0)
        {
            q = n / p;
            printf("%llu=%llu*%llu\n", n, q, p);
            return;
        }
    }

    /* If no factors are found, print n=1*n */
    printf("%llu=%llu*1\n", n, n);
}

/**
 * main - Reads numbers from a file and factors them
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned long long int n;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return (1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return (1);
    }

    /* Read each line and factorize the number */
    while (getline(&line, &len, file) != -1)
    {
        n = strtoull(line, NULL, 10);
        factorize(n);
    }

    free(line);
    fclose(file);
    return (0);
}
