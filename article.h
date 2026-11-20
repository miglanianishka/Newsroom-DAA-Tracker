#ifndef ARTICLE_H
#define ARTICLE_H

#define MAX_TITLE 200
#define MAX_SOURCE 50
#define MAX_CATEGORY 50
#define MAX_ARTICLES 1000

typedef struct
{
    int id;
    char source[MAX_SOURCE];
    char title[MAX_TITLE];
    char category[MAX_CATEGORY];

    int publicationTime;
    int priority;

} Article;

#endif