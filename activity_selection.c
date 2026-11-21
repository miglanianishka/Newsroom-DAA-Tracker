#include <stdio.h>
#include "algorithms.h"


// Structure for one newsroom activity
typedef struct
{
    char name[50];
    int start;
    int finish;

} Activity;
// Sort activities according to finishing time
void sortActivities(Activity activities[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (activities[j].finish >
                activities[j + 1].finish)
            {
                Activity temp = activities[j];

                activities[j] = activities[j + 1];

                activities[j + 1] = temp;
            }
        }
    }
}
// Greedy Activity Selection
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


    // Keeps track of selected activities
    int selected[10] = {0};
    // STEP 1: Sort activities by finishing time
    sortActivities(
        activities,
        n
    );
    printf("\n");
    printf("============================================================\n");
    printf("                 NEWSROOM TASK SCHEDULER\n");
    printf("============================================================\n");

    printf("\nAlgorithm : Greedy Activity Selection\n");
    printf("Strategy  : Select earliest finishing compatible task\n");
    // Display all activities
    printf("\nAVAILABLE REPORTING TASKS\n");
    printf("------------------------------------------------------------\n");
    printf(
        "%-22s %-10s %-10s\n",
        "Task",
        "Start",
        "Finish"
    );
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf(
            "%-22s %-10d %-10d\n",
            activities[i].name,
            activities[i].start,
            activities[i].finish
        );
    }
    // STEP 2: Select first activity
    int lastSelected = 0;
    selected[0] = 1;
    int selectedCount = 1;
    // STEP 3: Greedy selection
    for (int j = 1; j < n; j++)
    {
        /*
            Select activity only if its starting time
            is greater than or equal to the finishing
            time of the previously selected activity.
        */

        if (activities[j].start >=
            activities[lastSelected].finish)
        {
            selected[j] = 1;

            lastSelected = j;

            selectedCount++;
        }
    }
    // Display selected and rejected activities
    printf("\nGREEDY SELECTION PROCESS\n");
    printf("------------------------------------------------------------\n");


    for (int i = 0; i < n; i++)
    {
        printf(
            "%-22s (%d-%d)  ",
            activities[i].name,
            activities[i].start,
            activities[i].finish
        );


        if (selected[i])
        {
            printf("[SELECTED]\n");
        }
        else
        {
    printf("[NOT ASSIGNED - TIME CONFLICT]\n");
        }
        
    }
    // Visual schedule
   
    printf("\nREPORTER SCHEDULE\n");
    printf("------------------------------------------------------------\n");

    printf("Time : 9---10---11---12---13---14\n\n");


    for (int i = 0; i < n; i++)
    {
        if (selected[i])
        {
            printf(
                "%-20s %d",
                activities[i].name,
                activities[i].start
            );


            for (int t = activities[i].start;
                 t < activities[i].finish;
                 t++)
            {
                printf("----");
            }


            printf(
                "%d\n",
                activities[i].finish
            );
        }
    }
    printf("\nUNASSIGNED TASKS\n");
printf("------------------------------------------------------------\n");

for (int i = 0; i < n; i++)
{
    if (!selected[i])
    {
        printf(
            "%-22s (%d-%d)  -> Assign to another reporter\n",
            activities[i].name,
            activities[i].start,
            activities[i].finish
        );
    }
}
    // Final result

    printf("\n");
    printf("------------------------------------------------------------\n");

    printf(
        "Maximum Compatible Tasks : %d\n",
        selectedCount
    );

    printf(
        "Scheduling Status        : OPTIMAL GREEDY SCHEDULE\n"
    );

    printf("============================================================\n");
}
