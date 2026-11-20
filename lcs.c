#include <stdio.h>
#include <string.h>

#include "algorithms.h"
#include "searching.h"

int maxLCS(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

int longestCommonSubsequence(
    const char text1[],
    const char text2[]
)
{
    int m = strlen(text1);
    int n = strlen(text2);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] =
                    dp[i - 1][j - 1] + 1;
            }

            else
            {
                dp[i][j] =
                    maxLCS(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
            }
        }
    }

    return dp[m][n];
}

void compareArticlesLCS(
    Article articles[],
    int count,
    int id1,
    int id2
)
{
    int pos1 =
        linearSearch(articles, count, id1);

    int pos2 =
        linearSearch(articles, count, id2);

    if (pos1 == -1 || pos2 == -1)
    {
        printf("\nArticle not found.\n");
        return;
    }

    int lcs =
        longestCommonSubsequence(
            articles[pos1].title,
            articles[pos2].title
        );

    int len1 =
        strlen(articles[pos1].title);

    int len2 =
        strlen(articles[pos2].title);

    int maxLength;

    if (len1 > len2)
        maxLength = len1;
    else
        maxLength = len2;

    double similarity =
        ((double)lcs / maxLength) * 100;

    printf("\n===== RELATED STORY ANALYSIS =====\n");

    printf("\nArticle %d:\n%s\n",
           id1,
           articles[pos1].title);

    printf("\nArticle %d:\n%s\n",
           id2,
           articles[pos2].title);

    printf("\nLCS Length: %d\n", lcs);

    printf("Similarity: %.2f%%\n", similarity);

    if (similarity >= 50)
    {
        printf("Result: POSSIBLY RELATED STORIES\n");
    }
    else
    {
        printf("Result: DIFFERENT STORIES\n");
    }
}