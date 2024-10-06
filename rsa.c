#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * factorize - Factors the number n into two prime factors
 * @n: The number to factor
 *
 * Return: void
 */
void factorize(long long n)
{
    long long i;

    /* Try dividing n by numbers from 2 to sqrt(n) */
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            /* If i divides n evenly, print the factors */
            printf("%lld=%lld*%lld\n", n, i, n / i);
            return;
        }
    }

    /* If no factors found, print the number itself */
    printf("%lld=%lld*1\n", n, n);
}

/**
 * main - Reads a number from a file and factors it
 * @argc: The number of arguments
 * @argv: The argument vector (file path)
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    long long n;

    /* Check if the file path is provided */
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return (1);
    }

    /* Open the file containing the number */
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return (1);
    }

    /* Read the number from the file */
    if (fscanf(file, "%lld", &n) != 1)
    {
        fprintf(stderr, "Error: Could not read number from file %s\n", argv[1]);
        fclose(file);
        return (1);
    }

    /* Close the file */
    fclose(file);

    /* Factorize the number */
    factorize(n);

    return (0);
}
