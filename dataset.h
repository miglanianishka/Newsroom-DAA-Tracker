//dataset.h declares the functions that are implemented in dataset.c so that other files, especially main.c, can use them.
#ifndef DATASET_H
#define DATASET_H

#include "article.h"

int loadArticles(const char *filename, Article articles[]);
//There is a function called loadArticles(). It takes a filename and an Article array and returns no of articles.
void displayArticles(Article articles[], int count);
void displayOneArticle(Article article);

#endif