#include <stdio.h>
#include <string.h>

#include "algorithms.h"


// Stores the result of Maximum Subarray
typedef struct
{
    int left;
    int right;
    int sum;

} SubarrayResult;


// Kadane's Algorithm
SubarrayResult kadaneMaximumSubarray(
    int arr[],
    int n
)
{
    int currentSum = arr[0];
    int maxSum = arr[0];

    int currentStart = 0;

    int bestStart = 0;
    int bestEnd = 0;


    for (int i = 1; i < n; i++)
    {
        // Decide whether to continue the current subarray
        // or start a new subarray from the current element

        if (arr[i] > currentSum + arr[i])
        {
            currentSum = arr[i];
            currentStart = i;
        }
        else
        {
            currentSum =
                currentSum + arr[i];
        }


        // Update the best subarray found so far

        if (currentSum > maxSum)
        {
            maxSum = currentSum;

            bestStart = currentStart;
            bestEnd = i;
        }
    }


    SubarrayResult result;

    result.left = bestStart;
    result.right = bestEnd;
    result.sum = maxSum;


    return result;
}


// Breaking News Analyzer
void breakingNewsAnalyzer(
    Article articles[],
    int count
)
{
    // Change in newsroom activity over time
    int activity[] =
    {
        -2,
         3,
         5,
        -1,
         6,
         4,
        -7,
         2
    };


    int n =
        sizeof(activity) /
        sizeof(activity[0]);


    // Apply Kadane's Algorithm
    SubarrayResult result =
        kadaneMaximumSubarray(
            activity,
            n
        );


    printf("\n");
    printf("============================================================\n");
    printf("                  BREAKING NEWS ANALYZER\n");
    printf("============================================================\n");

    printf("\nAlgorithm : Kadane's Algorithm\n");
    printf("Purpose   : Maximum Subarray / Peak News Activity\n");


    printf("\nActivity Change Sequence:\n");

    for (int i = 0; i < n; i++)
    {
        printf(
            "%d ",
            activity[i]
        );
    }


    printf(
        "\n\nMaximum Activity Score : %d\n",
        result.sum
    );


    printf(
        "Peak Activity Interval : %d to %d\n",
        result.left + 1,
        result.right + 1
    );


    // Breaking-news threshold
    if (result.sum >= 10)
    {
        printf("\n");
        printf("------------------------------------------------------------\n");
        printf("                  BREAKING EVENT DETECTED\n");
        printf("------------------------------------------------------------\n");


        printf(
            "\nEvent Topic : DELHI HEAVY RAINFALL / FLOODING\n"
        );

        printf(
            "Category    : Weather\n"
        );


        int relatedCount = 0;


        printf("\nRelated News Reports:\n");
        printf("------------------------------------------------------------\n");


        for (int i = 0; i < count; i++)
        {
            // Find rainfall-related headlines
            if (
                strstr(
                    articles[i].title,
                    "rain"
                ) != NULL
                ||
                strstr(
                    articles[i].title,
                    "Rain"
                ) != NULL
            )
            {
                relatedCount++;


                printf(
                    "\n[%d] %s\n",
                    articles[i].id,
                    articles[i].title
                );


                printf(
                    "Source   : %s\n",
                    articles[i].source
                );


                printf(
                    "Time     : %d\n",
                    articles[i].publicationTime
                );


                printf(
                    "Priority : %d\n",
                    articles[i].priority
                );
            }
        }


        printf("\n");
        printf("------------------------------------------------------------\n");


        printf(
            "Related Reports : %d\n",
            relatedCount
        );


        printf(
            "Activity Score  : %d\n",
            result.sum
        );


        printf(
            "Alert Level     : HIGH\n"
        );


        printf(
            "Status          : BREAKING NEWS\n"
        );
    }


    else
    {
        printf("\n");
        printf("------------------------------------------------------------\n");

        printf(
            "No major breaking event detected.\n"
        );

        printf(
            "Status : NORMAL NEWS ACTIVITY\n"
        );
    }


    printf("============================================================\n");
}