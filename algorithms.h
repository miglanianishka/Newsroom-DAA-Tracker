#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "article.h"


// NAIVE PATTERN MATCHING

int naivePatternSearch(
    const char text[],
    const char pattern[]
);

void searchKeywordNaive(
    Article articles[],
    int count,
    const char keyword[]
);


// RABIN-KARP

int rabinKarpSearch(
    const char text[],
    const char pattern[]
);

void searchKeywordRabinKarp(
    Article articles[],
    int count,
    const char keyword[]
);


// LCS

int longestCommonSubsequence(
    const char text1[],
    const char text2[]
);

void compareArticlesLCS(
    Article articles[],
    int count,
    int id1,
    int id2
);


// BREAKING NEWS - MAXIMUM SUBARRAY

void breakingNewsAnalyzer(
    Article articles[],
    int count
);


// ACTIVITY SELECTION

void activitySelectionDemo();


// HUFFMAN CODING

void huffmanDemo();


#endif