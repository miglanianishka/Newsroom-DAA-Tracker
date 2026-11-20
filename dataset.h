//dataset.h declares the functions that are implemented in dataset.c so that other files, especially main.c, can use them.
#ifndef DATASET_H
#define DATASET_H

#include "article.h"

int loadArticles(const char *filename, Article articles[]);
void displayArticles(Article articles[], int count);
void displayOneArticle(Article article);

#endif