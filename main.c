#include <stdio.h>

#include "article.h"
#include "dataset.h"
#include "sorting.h"
#include "searching.h"
#include "algorithms.h"


// ============================================================
// MAIN MENU
// ============================================================

void showMenu()
{
    printf("\n");
    printf("============================================================\n");
    printf("              NEWSROOM INTELLIGENCE SYSTEM\n");
    printf("         Duplicate Story & Breaking Event Tracker\n");
    printf("============================================================\n");

    printf("\n");
    printf("---------------------- NEWS OPERATIONS ---------------------\n");
    printf(" 1. View News Feed\n");
    printf(" 2. Chronological News Feed       [Merge Sort]\n");
    printf(" 3. Priority News Ranking         [Quick Sort]\n");

    printf("\n");
    printf("----------------------- SEARCH CENTER ----------------------\n");
    printf(" 4. Search Article by ID          [Linear Search]\n");
    printf(" 5. Fast Article Search           [Iterative Binary Search]\n");
    printf(" 6. Recursive Article Search      [Recursive Binary Search]\n");
    printf(" 7. Search Headlines by Keyword   [Naive Pattern Matching]\n");
    printf(" 8. Hash-Based Keyword Search     [Rabin-Karp]\n");

    printf("\n");
    printf("------------------- NEWS INTELLIGENCE ----------------------\n");
    printf(" 9. Related Story Detector        [LCS]\n");
    printf("10. Breaking News Analyzer        [Maximum Subarray]\n");
    printf("11. Reporter Task Scheduler       [Activity Selection]\n");
    printf("12. Article Compression           [Huffman Coding]\n");

    printf("\n");
    printf("------------------------------------------------------------\n");
    printf(" 0. Exit\n");
    printf("============================================================\n");
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    Article articles[MAX_ARTICLES];

    int count;
    int choice;


    // --------------------------------------------------------
    // LOAD DATASET
    // --------------------------------------------------------

    count = loadArticles(
        "data/articles.csv",
        articles
    );


    if (count == 0)
    {
        printf("\nError: No articles loaded.\n");
        return 1;
    }


    // --------------------------------------------------------
    // STARTUP INFORMATION
    // --------------------------------------------------------

    printf("\n");
    printf("============================================================\n");
    printf("                  SYSTEM INITIALIZATION\n");
    printf("============================================================\n");

    printf("Dataset Status : LOADED SUCCESSFULLY\n");
    printf("Articles Loaded: %d\n", count);
    printf("Data Source    : data/articles.csv\n");

    printf("============================================================\n");


    // --------------------------------------------------------
    // MENU LOOP
    // --------------------------------------------------------

    do
    {
        showMenu();

        printf("\nSelect operation: ");
        scanf("%d", &choice);


        switch (choice)
        {

            // =================================================
            // OPTION 1 - DISPLAY NEWS FEED
            // =================================================

            case 1:
            {
                printf("\n");
                printf("============================================================\n");
                printf("                        NEWS FEED\n");
                printf("============================================================\n");

                displayArticles(
                    articles,
                    count
                );

                break;
            }


            // =================================================
            // OPTION 2 - MERGE SORT
            // =================================================

            case 2:
            {
                mergeSortByTime(
                    articles,
                    0,
                    count - 1
                );


                printf("\n");
                printf("============================================================\n");
                printf("                  CHRONOLOGICAL NEWS FEED\n");
                printf("============================================================\n");

                printf(
                    "Algorithm : Merge Sort\n"
                );

                printf(
                    "Sorted By : Publication Time\n"
                );

                printf("------------------------------------------------------------\n");


                displayArticles(
                    articles,
                    count
                );


                break;
            }


            // =================================================
            // OPTION 3 - QUICK SORT
            // =================================================

            case 3:
            {
                quickSortByPriority(
                    articles,
                    0,
                    count - 1
                );


                printf("\n");
                printf("============================================================\n");
                printf("                    PRIORITY NEWS RANKING\n");
                printf("============================================================\n");

                printf(
                    "Algorithm : Quick Sort\n"
                );

                printf(
                    "Order     : Highest Priority First\n"
                );

                printf("------------------------------------------------------------\n");


                displayArticles(
                    articles,
                    count
                );


                break;
            }


            // =================================================
            // OPTION 4 - LINEAR SEARCH
            // =================================================

            case 4:
            {
                int targetID;


                printf(
                    "\nEnter Article ID: "
                );

                scanf(
                    "%d",
                    &targetID
                );


                int position =
                    linearSearch(
                        articles,
                        count,
                        targetID
                    );


                printf("\n");
                printf("============================================================\n");
                printf("                      SEARCH RESULT\n");
                printf("============================================================\n");

                printf(
                    "Algorithm : Linear Search\n"
                );


                if (position != -1)
                {
                    printf(
                        "Status    : ARTICLE FOUND\n"
                    );

                    displayOneArticle(
                        articles[position]
                    );
                }

                else
                {
                    printf(
                        "Status    : ARTICLE NOT FOUND\n"
                    );
                }


                break;
            }


            // =================================================
            // OPTION 5 - ITERATIVE BINARY SEARCH
            // =================================================

            case 5:
            {
                int targetID;


                printf(
                    "\nEnter Article ID: "
                );

                scanf(
                    "%d",
                    &targetID
                );


                /*
                    Binary Search requires sorted data.

                    Therefore, first sort the articles
                    according to ID using Merge Sort.
                */

                mergeSortByID(
                    articles,
                    0,
                    count - 1
                );


                int position =
                    binarySearchIterative(
                        articles,
                        count,
                        targetID
                    );


                printf("\n");
                printf("============================================================\n");
                printf("                     FAST SEARCH RESULT\n");
                printf("============================================================\n");

                printf(
                    "Algorithm : Iterative Binary Search\n"
                );


                if (position != -1)
                {
                    printf(
                        "Status    : ARTICLE FOUND\n"
                    );

                    displayOneArticle(
                        articles[position]
                    );
                }

                else
                {
                    printf(
                        "Status    : ARTICLE NOT FOUND\n"
                    );
                }


                break;
            }


            // =================================================
            // OPTION 6 - RECURSIVE BINARY SEARCH
            // =================================================

            case 6:
            {
                int targetID;


                printf(
                    "\nEnter Article ID: "
                );

                scanf(
                    "%d",
                    &targetID
                );


                /*
                    Binary Search requires
                    ID-sorted articles.
                */

                mergeSortByID(
                    articles,
                    0,
                    count - 1
                );


                int position =
                    binarySearchRecursive(
                        articles,
                        0,
                        count - 1,
                        targetID
                    );


                printf("\n");
                printf("============================================================\n");
                printf("                  RECURSIVE SEARCH RESULT\n");
                printf("============================================================\n");

                printf(
                    "Algorithm : Recursive Binary Search\n"
                );


                if (position != -1)
                {
                    printf(
                        "Status    : ARTICLE FOUND\n"
                    );

                    displayOneArticle(
                        articles[position]
                    );
                }

                else
                {
                    printf(
                        "Status    : ARTICLE NOT FOUND\n"
                    );
                }


                break;
            }


            // =================================================
            // OPTION 7 - NAIVE PATTERN MATCHING
            // =================================================

            case 7:
            {
                char keyword[100];


                printf(
                    "\nEnter headline keyword: "
                );


                scanf(
                    " %99[^\n]",
                    keyword
                );


                printf("\n");
                printf("============================================================\n");
                printf("                    KEYWORD SEARCH\n");
                printf("============================================================\n");

                printf(
                    "Algorithm : Naive Pattern Matching\n"
                );

                printf(
                    "Keyword   : %s\n",
                    keyword
                );


                searchKeywordNaive(
                    articles,
                    count,
                    keyword
                );


                break;
            }


            // =================================================
            // OPTION 8 - RABIN-KARP
            // =================================================

            case 8:
            {
                char keyword[100];


                printf(
                    "\nEnter headline keyword: "
                );


                scanf(
                    " %99[^\n]",
                    keyword
                );


                printf("\n");
                printf("============================================================\n");
                printf("                  HASH-BASED KEYWORD SEARCH\n");
                printf("============================================================\n");

                printf(
                    "Algorithm : Rabin-Karp\n"
                );

                printf(
                    "Keyword   : %s\n",
                    keyword
                );


                searchKeywordRabinKarp(
                    articles,
                    count,
                    keyword
                );


                break;
            }


            // =================================================
            // OPTION 9 - LCS RELATED STORY DETECTOR
            // =================================================

            case 9:
            {
                int id1;
                int id2;


                printf(
                    "\nEnter first Article ID: "
                );

                scanf(
                    "%d",
                    &id1
                );


                printf(
                    "Enter second Article ID: "
                );

                scanf(
                    "%d",
                    &id2
                );


                compareArticlesLCS(
                    articles,
                    count,
                    id1,
                    id2
                );


                break;
            }


            // =================================================
            // OPTION 10 - BREAKING NEWS ANALYZER
            // =================================================

            case 10:
            {
                breakingNewsAnalyzer(
                    articles,
                    count
                );


                break;
            }


            // =================================================
            // OPTION 11 - ACTIVITY SELECTION
            // =================================================

            case 11:
            {
                activitySelectionDemo();


                break;
            }


            // =================================================
            // OPTION 12 - HUFFMAN CODING
            // =================================================

            case 12:
            {
                huffmanDemo();


                break;
            }


            // =================================================
            // EXIT
            // =================================================

            case 0:
            {
                printf("\n");
                printf("============================================================\n");
                printf("              NEWSROOM SYSTEM TERMINATED\n");
                printf("============================================================\n");

                break;
            }


            // =================================================
            // INVALID INPUT
            // =================================================

            default:
            {
                printf("\n");
                printf("Invalid choice. Please select an option from 0 to 12.\n");

                break;
            }
        }

    }
    while (choice != 0);


    return 0;
}