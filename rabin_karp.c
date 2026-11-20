#include <stdio.h>
#include <string.h>

#include "algorithms.h"

int rabinKarpSearch(const char text[], const char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    if (m == 0)
        return 0;

    if (m > n)
        return -1;

    int base = 256;
    int prime = 101;

    int patternHash = 0;
    int textHash = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * base) % prime;
    }

    for (int i = 0; i < m; i++)
    {
        patternHash =
            (base * patternHash + pattern[i]) % prime;

        textHash =
            (base * textHash + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (patternHash == textHash)
        {
            int j;

            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }

            if (j == m)
            {
                return i;
            }
        }

        if (i < n - m)
        {
            textHash =
                (base *
                 (textHash - text[i] * h)
                 + text[i + m]) % prime;

            if (textHash < 0)
            {
                textHash += prime;
            }
        }
    }

    return -1;
}

void searchKeywordRabinKarp(
    Article articles[],
    int count,
    const char keyword[]
)
{
    int found = 0;

    printf("\n--- RABIN-KARP KEYWORD SEARCH ---\n");

    for (int i = 0; i < count; i++)
    {
        if (rabinKarpSearch(
                articles[i].title,
                keyword) != -1)
        {
            printf("\nID: %d\n", articles[i].id);
            printf("Title: %s\n", articles[i].title);

            found++;
        }
    }

    printf("\nTotal matching articles: %d\n", found);
}