#ifndef SEARCHING_H
#define SEARCHING_H
#include "article.h"
int linearSearch(
    Article articles[],
    int count,
    int targetID
);
int binarySearchIterative(
    Article articles[],
    int count,
    int targetID
);
int binarySearchRecursive(
    Article articles[],
    int low,
    int high,
    int targetID
);
#endif