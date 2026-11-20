# Newsroom Duplicate Story & Breaking Event Tracker

## Complexity Analysis Report

### Project Overview

The Newsroom Duplicate Story and Breaking Event Tracker is a
terminal-based C application that applies Design and Analysis
of Algorithms concepts to digital news processing.

The system loads news articles from a CSV dataset and uses
different algorithms for sorting, searching, related-story
detection, breaking-event analysis, task scheduling and
compression.
## Algorithms Implemented

| Algorithm | Paradigm | Application |
|---|---|---|
| Merge Sort | Divide and Conquer | Chronological article sorting |
| Quick Sort | Divide and Conquer | Priority ranking |
| Linear Search | Searching | Article ID search |
| Iterative Binary Search | Divide and Conquer | Fast Article ID search |
| Recursive Binary Search | Divide and Conquer | Recursive ID search |
| Naive Pattern Matching | String Matching | Keyword search |
| Rabin-Karp | Hashing | Hash-based keyword search |
| LCS | Dynamic Programming | Related-story detection |
| Maximum Subarray | Divide and Conquer | Breaking-news activity detection |
| Activity Selection | Greedy | Reporter task scheduling |
| Huffman Coding | Greedy | Article text compression |
## Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case | Space |
|---|---|---|---|---|
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) average |
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Iterative Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Recursive Binary Search | O(1) | O(log n) | O(log n) | O(log n) |
| Naive Pattern Matching | - | - | O(nm) | O(1) |
| Rabin-Karp | - | O(n+m) expected | O(nm) | O(1) |
| LCS | O(mn) | O(mn) | O(mn) | O(mn) |
| Maximum Subarray | O(n log n) | O(n log n) | O(n log n) | O(log n) |
| Activity Selection | - | O(n)* | O(n)* | O(1) |
*Activity Selection takes O(n) after activities have been
sorted according to finishing time.
## Merge Sort

### Purpose
Merge Sort is used to arrange incoming news articles according
to publication time. It is also used to sort Article IDs before
Binary Search.

### Design Paradigm
Divide and Conquer

### Complexity
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)
- Auxiliary Space: O(n)

### Reason for Selection
Merge Sort provides predictable O(n log n) performance and is
stable in the current implementation.