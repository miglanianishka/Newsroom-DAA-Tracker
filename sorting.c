#include "sorting.h"


// ==================================================
// MERGE SORT BY PUBLICATION TIME
// ==================================================

void mergeByTime(Article articles[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Article L[n1];
    Article R[n2];

    int i, j, k;

    for (i = 0; i < n1; i++)
    {
        L[i] = articles[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = articles[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].publicationTime <= R[j].publicationTime)
        {
            articles[k] = L[i];
            i++;
        }
        else
        {
            articles[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        articles[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        articles[k] = R[j];
        j++;
        k++;
    }
}


void mergeSortByTime(Article articles[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSortByTime(articles, left, mid);
        mergeSortByTime(articles, mid + 1, right);

        mergeByTime(articles, left, mid, right);
    }
}


// ==================================================
// MERGE SORT BY ARTICLE ID
// ==================================================

void mergeByID(Article articles[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Article L[n1];
    Article R[n2];

    int i, j, k;

    for (i = 0; i < n1; i++)
    {
        L[i] = articles[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = articles[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].id <= R[j].id)
        {
            articles[k] = L[i];
            i++;
        }
        else
        {
            articles[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        articles[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        articles[k] = R[j];
        j++;
        k++;
    }
}


void mergeSortByID(Article articles[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSortByID(articles, left, mid);
        mergeSortByID(articles, mid + 1, right);

        mergeByID(articles, left, mid, right);
    }
}


// ==================================================
// QUICK SORT BY PRIORITY
// ==================================================

void swapArticles(Article *a, Article *b)
{
    Article temp = *a;
    *a = *b;
    *b = temp;
}


int partitionByPriority(Article articles[], int low, int high)
{
    int pivot = articles[high].priority;

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        // Higher priority first
        if (articles[j].priority >= pivot)
        {
            i++;

            swapArticles(&articles[i], &articles[j]);
        }
    }

    swapArticles(&articles[i + 1], &articles[high]);

    return i + 1;
}


void quickSortByPriority(Article articles[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex =
            partitionByPriority(articles, low, high);

        quickSortByPriority(
            articles,
            low,
            pivotIndex - 1
        );

        quickSortByPriority(
            articles,
            pivotIndex + 1,
            high
        );
    }
}