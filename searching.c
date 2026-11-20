#include "searching.h"
// LINEAR SEARCH
int linearSearch(
    Article articles[],
    int count,
    int targetID
)
{
    for (int i = 0; i < count; i++)
    {
        if (articles[i].id == targetID)
        {
            return i;
        }
    }

    return -1;
}
// ITERATIVE BINARY SEARCH
int binarySearchIterative(
    Article articles[],
    int count,
    int targetID
)
{
    int low = 0;
    int high = count - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (articles[mid].id == targetID)
        {
            return mid;
        }

        else if (articles[mid].id < targetID)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
// RECURSIVE BINARY SEARCH
int binarySearchRecursive(
    Article articles[],
    int low,
    int high,
    int targetID
)
{
    // Base condition
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (articles[mid].id == targetID)
    {
        return mid;
    }

    else if (articles[mid].id < targetID)
    {
        return binarySearchRecursive(
            articles,
            mid + 1,
            high,
            targetID
        );
    }

    else
    {
        return binarySearchRecursive(
            articles,
            low,
            mid - 1,
            targetID
        );
    }
}