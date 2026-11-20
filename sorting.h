#ifndef SORTING_H
#define SORTING_H

#include "article.h"

void mergeSortByTime(Article articles[], int left, int right);

void mergeSortByID(Article articles[], int left, int right);

void quickSortByPriority(Article articles[], int low, int high);

#endif