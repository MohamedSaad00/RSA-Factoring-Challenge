#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - Function to find two factors of a number
 * @n: The number to factorize
 *
 * Return: 0 on success
 */
void factorize(unsigned long n)
{
    unsigned long p;

    /* Check for the smallest factor starting from 2 */
    if (n % 2 == 0)
    {
        printf("%lu=%lu*2\n", n, n / 2);
        return;
    }

    /* Check for odd factors starting from 3 up to the square root of n */
    for (p = 3; p * p <= n; p += 2)
    {
        if (n % p == 0)
        {
            printf("%lu=%lu*%lu\n", n, n / p, p);
            return;
        }
    }

    /* If no factors are found, the number is prime or 1*n */
    printf("%lu=%lu*1\n", n, n);
}

/**
 * main - Entry point of the program
 * @argc: The argument count
 * @argv: The argument vector (contains file name)
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned long n;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return (1);
    }

    /* Open the file */
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return (1);
    }

    /* Read each line from the file */
    while ((read = getline(&line, &len, file)) != -1)
    {
        /* Convert the line to an unsigned long integer */
        n = strtoul(line, NULL, 10);

        /* Factorize the number */
        factorize(n);
    }

    /* Clean up and close the file */
    free(line);
    fclose(file);

    return (0);
}
