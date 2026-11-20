#include <stdio.h>

#include "algorithms.h"

typedef struct
{
    char name[50];
    int start;
    int finish;

} Activity;

void sortActivities(
    Activity activities[],
    int n
)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (activities[j].finish >
                activities[j + 1].finish)
            {
                Activity temp =
                    activities[j];

                activities[j] =
                    activities[j + 1];

                activities[j + 1] =
                    temp;
            }
        }
    }
}

void activitySelectionDemo()
{
    Activity activities[] =
    {
        {"Weather Update", 9, 10},
        {"Political Interview", 9, 12},
        {"Flood Coverage", 10, 11},
        {"Sports Update", 11, 12},
        {"Press Conference", 12, 14}
    };

    int n =
        sizeof(activities) /
        sizeof(activities[0]);

    sortActivities(
        activities,
        n
    );

    printf("\n===== NEWSROOM TASK SCHEDULER =====\n");

    printf("\nSelected Activities:\n");

    int i = 0;
    int selected = 1;

    printf(
        "%s (%d-%d)\n",
        activities[i].name,
        activities[i].start,
        activities[i].finish
    );

    for (int j = 1; j < n; j++)
    {
        if (activities[j].start >=
            activities[i].finish)
        {
            printf(
                "%s (%d-%d)\n",
                activities[j].name,
                activities[j].start,
                activities[j].finish
            );

            i = j;

            selected++;
        }
    }

    printf(
        "\nMaximum Compatible Activities: %d\n",
        selected
    );
}