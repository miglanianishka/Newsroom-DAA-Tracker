#include <stdio.h>
#include "dataset.h"
int loadArticles(const char *filename, Article articles[])
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening dataset!\n");
        return 0;
    }
    char header[500];
    // Skip CSV header
    fgets(header, 500, file);
    int count = 0;
    while (count < MAX_ARTICLES &&
           fscanf(file,
                  "%d,%49[^,],%199[^,],%49[^,],%d,%d\n",
                  &articles[count].id,
                  articles[count].source,
                  articles[count].title,
                  articles[count].category,
                  &articles[count].publicationTime,
                  &articles[count].priority) == 6)
    {
        count++;
    }
    fclose(file);
    return count;
}
void displayArticles(Article articles[], int count)
{
    printf("\n================ NEWS ARTICLES ================\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nID: %d\n", articles[i].id);
        printf("Source: %s\n", articles[i].source);
        printf("Title: %s\n", articles[i].title);
        printf("Category: %s\n", articles[i].category);
        printf("Time: %d\n", articles[i].publicationTime);
        printf("Priority: %d\n", articles[i].priority);
    }

    printf("\n================================================\n");
}
void displayOneArticle(Article article)
{
    printf("\nArticle Found!\n");
    printf("------------------------------\n");

    printf("ID: %d\n", article.id);
    printf("Source: %s\n", article.source);
    printf("Title: %s\n", article.title);
    printf("Category: %s\n", article.category);
    printf("Time: %d\n", article.publicationTime);
    printf("Priority: %d\n", article.priority);
}