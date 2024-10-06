#include <stdio.h>
#include <stdlib.h>

/* Function to find two factors of a number */
void factorize(unsigned long long int n) {
    unsigned long long int p, q;

    for (p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            q = n / p;
            printf("%llu=%llu*%llu\n", n, q, p);
            return;
        }
    }
    /* If no factors found, it must be a prime number */
    printf("%llu=%llu*1\n", n, n);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned long long int n;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    /* Read each line and factorize the number */
    while (getline(&line, &len, file) != -1) {
        n = strtoull(line, NULL, 10);
        factorize(n);
    }

    free(line);
    fclose(file);
    return 0;
}
