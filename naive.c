#include <stdio.h>
#include <string.h>

#include "algorithms.h"

int naivePatternSearch(const char text[], const char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    if (m == 0)
        return 0;

    if (m > n)
        return -1;

    for (int i = 0; i <= n - m; i++)
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

    return -1;
}

void searchKeywordNaive(
    Article articles[],
    int count,
    const char keyword[]
)
{
    int found = 0;

    printf("\n--- NAIVE KEYWORD SEARCH ---\n");

    for (int i = 0; i < count; i++)
    {
        if (naivePatternSearch(
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