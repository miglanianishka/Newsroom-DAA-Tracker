#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "algorithms.h"


typedef struct
{
    int left;
    int right;
    int sum;

} SubarrayResult;


// Finds maximum subarray crossing the midpoint

SubarrayResult maxCrossingSubarray(
    int arr[],
    int low,
    int mid,
    int high
)
{
    int sum = 0;

    int leftSum = INT_MIN;
    int maxLeft = mid;

    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];

        if (sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }


    sum = 0;

    int rightSum = INT_MIN;
    int maxRight = mid + 1;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];

        if (sum > rightSum)
        {
            rightSum = sum;
            maxRight = i;
        }
    }


    SubarrayResult result;

    result.left = maxLeft;
    result.right = maxRight;
    result.sum = leftSum + rightSum;

    return result;
}


// Divide-and-Conquer Maximum Subarray

SubarrayResult maximumSubarray(
    int arr[],
    int low,
    int high
)
{
    // Base case
    if (low == high)
    {
        SubarrayResult result;

        result.left = low;
        result.right = high;
        result.sum = arr[low];

        return result;
    }


    int mid = (low + high) / 2;


    SubarrayResult leftResult =
        maximumSubarray(
            arr,
            low,
            mid
        );


    SubarrayResult rightResult =
        maximumSubarray(
            arr,
            mid + 1,
            high
        );


    SubarrayResult crossResult =
        maxCrossingSubarray(
            arr,
            low,
            mid,
            high
        );


    if (leftResult.sum >= rightResult.sum &&
        leftResult.sum >= crossResult.sum)
    {
        return leftResult;
    }


    if (rightResult.sum >= leftResult.sum &&
        rightResult.sum >= crossResult.sum)
    {
        return rightResult;
    }


    return crossResult;
}


// Breaking News Analyzer

void breakingNewsAnalyzer(
    Article articles[],
    int count
)
{
    /*
        Change in newsroom activity
        over consecutive time intervals.
    */

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


    SubarrayResult result =
        maximumSubarray(
            activity,
            0,
            n - 1
        );


    printf("\n");
    printf("============================================================\n");
    printf("                  BREAKING NEWS ANALYZER\n");
    printf("============================================================\n");


    printf("\nAnalyzing newsroom activity...\n");


    printf("\nActivity Change Sequence:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", activity[i]);
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


    // Breaking threshold

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

        printf(
            "------------------------------------------------------------\n"
        );


        for (int i = 0; i < count; i++)
        {
            /*
                Select articles containing
                rain or Rain in the headline.
            */

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
        printf(
            "------------------------------------------------------------\n"
        );


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
        printf(
            "------------------------------------------------------------\n"
        );

        printf(
            "No major breaking event detected.\n"
        );

        printf(
            "Status: NORMAL NEWS ACTIVITY\n"
        );
    }


    printf(
        "============================================================\n"
    );
}