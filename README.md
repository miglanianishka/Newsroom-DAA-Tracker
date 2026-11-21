# Newsroom Duplicate Story & Breaking Event Tracker

## Complexity Analysis Report

### Project Overview

The **Newsroom Duplicate Story & Breaking Event Tracker** is a terminal-based C application that applies concepts from **Design and Analysis of Algorithms (DAA)** to digital news processing.

The system loads news articles from a CSV dataset and uses different algorithms for:

- Sorting and ranking news articles
- Searching articles by ID
- Searching keywords inside headlines
- Detecting potentially related news stories
- Detecting periods of high newsroom activity
- Scheduling reporter tasks
- Compressing news text

The project demonstrates the practical use of **Divide and Conquer, Dynamic Programming, Greedy Algorithms, Searching, String Matching, Hashing, Min-Heaps, and Maximum Subarray optimization**.

---

## Algorithms Implemented

| Algorithm | Paradigm / Technique | Application |
|---|---|---|
| Merge Sort | Divide and Conquer | Chronological and ID sorting |
| Quick Sort | Divide and Conquer | Priority ranking |
| Linear Search | Sequential Searching | Article ID search |
| Iterative Binary Search | Divide and Conquer | Fast Article ID search |
| Recursive Binary Search | Divide and Conquer | Recursive Article ID search |
| Naive Pattern Matching | String Matching | Keyword search |
| Rabin-Karp | Hashing / Rolling Hash | Hash-based keyword search |
| LCS | Dynamic Programming | Related-story detection |
| Kadane's Algorithm | Maximum Subarray Optimization | Breaking-news activity detection |
| Activity Selection | Greedy | Reporter task scheduling |
| Huffman Coding | Greedy + Min-Heap | Article text compression |

---

## Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case | Auxiliary Space |
|---|---|---|---|---|
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) average |
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Iterative Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Recursive Binary Search | O(1) | O(log n) | O(log n) | O(log n) |
| Naive Pattern Matching | O(n)* | O(n)* | O(nm) | O(1) |
| Rabin-Karp | O(n+m) expected | O(n+m) expected | O(nm) | O(1) |
| LCS | O(mn) | O(mn) | O(mn) | O(mn) |
| Kadane's Algorithm | O(n) | O(n) | O(n) | O(1) |
| Activity Selection | O(n)** | O(n)** | O(n)** | O(1) |
| Huffman Coding with Min-Heap | O(k log k) | O(k log k) | O(k log k) | O(k) |

\* For Naive Pattern Matching, O(n) represents a favorable case where mismatches occur early. The worst case is O(nm).

\** Greedy Activity Selection itself takes O(n) after activities have been sorted by finishing time. The current prototype uses a simple nested-loop sorting method taking O(n²), so the complete current scheduling implementation is O(n²).

Where:

- `n` = number of elements or text length depending on the algorithm
- `m` = pattern length or second-string length
- `k` = number of distinct characters in Huffman Coding

---

## Merge Sort

### Purpose

Merge Sort is used to arrange incoming news articles according to **publication time**. It is also used to sort articles according to **Article ID** before performing Binary Search.

### Design Paradigm

**Divide and Conquer**

### Working

Merge Sort follows three main steps:

1. Divide the array into two halves.
2. Recursively sort both halves.
3. Merge the sorted halves.

### Recurrence

`T(n) = 2T(n/2) + O(n)`

### Complexity

- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)
- Auxiliary Space: O(n)

### Reason for Selection

Merge Sort provides predictable **O(n log n)** performance and is stable in the current implementation. It is useful for chronological organization and for preparing ID-sorted data for Binary Search.

---

## Quick Sort

### Purpose

Quick Sort is used to rank news articles according to their **editorial priority**, from highest to lowest.

The priority value is stored as prototype editorial metadata. Quick Sort does not calculate the priority; it only ranks articles using the existing priority score.

### Design Paradigm

**Divide and Conquer**

### Working

1. Select a pivot.
2. Partition the array around the pivot.
3. Place the pivot in its appropriate position.
4. Recursively sort the left and right partitions.

### Complexity

- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n²)
- Average Auxiliary Space: O(log n)

### Reason for Selection

Quick Sort provides efficient average-case performance and demonstrates pivot-based Divide and Conquer.

Its worst case occurs when pivot selection repeatedly produces highly unbalanced partitions.

---

## Merge Sort vs Quick Sort

| Property | Merge Sort | Quick Sort |
|---|---|---|
| Paradigm | Divide and Conquer | Divide and Conquer |
| Average Time | O(n log n) | O(n log n) |
| Worst Time | O(n log n) | O(n²) |
| Auxiliary Memory | O(n) | O(log n) average |
| Stable in Current Implementation | Yes | No |
| Main Operation | Merge | Partition |

Neither algorithm is inherently restricted to publication time or priority. Different comparison fields can be used with either algorithm.

---

## Linear Search

### Purpose

Linear Search is used to find an article using its exact Article ID without requiring the dataset to be sorted.

### Working

The algorithm checks articles sequentially until the required ID is found or the complete array has been searched.

### Complexity

- Best Case: O(1)
- Average Case: O(n)
- Worst Case: O(n)
- Auxiliary Space: O(1)

### Reason for Selection

Linear Search provides a simple baseline search algorithm and works directly on unsorted data.

---

## Binary Search

### Purpose

Binary Search provides efficient Article ID retrieval from sorted data.

Both implementations are included:

- Iterative Binary Search
- Recursive Binary Search

### Requirement

Binary Search requires the articles to be sorted according to Article ID.

The project therefore uses the following workflow:

`Unsorted IDs → Merge Sort by ID → Binary Search`

### Complexity

| Version | Best | Average | Worst | Auxiliary Space |
|---|---|---|---|---|
| Iterative | O(1) | O(log n) | O(log n) | O(1) |
| Recursive | O(1) | O(log n) | O(log n) | O(log n) |

The recursive implementation requires additional stack memory.

### Preprocessing Cost

Binary Search itself takes **O(log n)**.

However, if an unsorted dataset must first be sorted using Merge Sort for a single search, the complete operation is dominated by:

`O(n log n)`

In a larger system, an ID-sorted index could be maintained to avoid repeated sorting.

---

## Linear Search vs Binary Search

| Property | Linear Search | Binary Search |
|---|---|---|
| Worst Time | O(n) | O(log n) |
| Sorted Data Required | No | Yes |
| Preprocessing Required | No | Possibly |
| Iterative Auxiliary Space | O(1) | O(1) |

Linear Search is useful for unsorted or small datasets, while Binary Search is significantly more efficient for repeated searching on sorted data.

---

## Naive Pattern Matching

### Purpose

Naive Pattern Matching searches for a keyword inside news headlines.

### Working

The pattern is placed at every valid starting position in the headline and compared character-by-character.

If a mismatch occurs, the pattern shifts by one position.

### Complexity

Let:

- `n` = headline length
- `m` = keyword length

Favorable Case: O(n)

Worst Case: O(nm)

Auxiliary Space: O(1)

### Reason for Selection

Naive Pattern Matching provides a simple direct-comparison baseline that can be compared with Rabin-Karp.

---

## Rabin-Karp Algorithm

### Purpose

Rabin-Karp provides hash-based keyword searching inside news headlines.

### Working

1. Calculate the hash of the keyword.
2. Calculate the hash of the first headline window.
3. Compare the hashes.
4. If the hashes match, verify the actual characters.
5. Move to the next window using a rolling hash.

### Hash Collision

Two different strings can sometimes produce the same hash value.

Therefore, when hashes match, the actual characters must still be compared.

### Complexity

- Expected Time: O(n + m)
- Worst Case: O(nm)
- Auxiliary Space: O(1)

The worst case can occur when repeated hash collisions require character-by-character verification.

---

## Naive Pattern Matching vs Rabin-Karp

| Property | Naive | Rabin-Karp |
|---|---|---|
| Main Technique | Character comparison | Hashing |
| Rolling Hash | No | Yes |
| Hash Collision | No | Possible |
| Worst Case | O(nm) | O(nm) |
| Main Advantage | Simplicity | Efficient hash-based filtering |

Rabin-Karp is not always faster. For small texts or early mismatches, Naive Pattern Matching can perform well. Rabin-Karp becomes more useful when hashing avoids repeated character comparisons.

---

## Longest Common Subsequence (LCS)

### Purpose

LCS is used for **related-story detection**.

Two headlines can describe the same event while using different wording. LCS measures the amount of ordered textual information shared by the two headlines.

### Design Paradigm

**Dynamic Programming**

### Recurrence

If the current characters match:

`LCS[i][j] = 1 + LCS[i-1][j-1]`

Otherwise:

`LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1])`

### Complexity

- Best Case: O(mn)
- Average Case: O(mn)
- Worst Case: O(mn)
- Auxiliary Space: O(mn)

The implementation fills the complete Dynamic Programming table regardless of the similarity of the input headlines.

### Similarity Score

The prototype calculates:

`Similarity = (LCS Length / Longer Headline Length) × 100`

A configurable threshold is then used to flag potentially related stories.

The threshold is **application-level logic** and is not part of the LCS algorithm itself.

### Limitation

LCS measures textual sequence similarity, not complete semantic meaning.

---

## Kadane's Algorithm

### Purpose

Kadane's Algorithm is used in the **Breaking News Analyzer** to identify the strongest continuous period of newsroom activity.

### Problem

Given a sequence of changes in newsroom activity, the system needs to identify the continuous interval having the maximum cumulative activity score.

### Working

At every position, Kadane's Algorithm decides whether to:

- Continue the current subarray, or
- Start a new subarray from the current element.

The algorithm maintains:

- `currentSum` — best subarray sum ending at the current position
- `maxSum` — best subarray sum found overall

Conceptually:

`currentSum = max(arr[i], currentSum + arr[i])`

### Complexity

- Best Case: O(n)
- Average Case: O(n)
- Worst Case: O(n)
- Auxiliary Space: O(1)

### Comparison with Other Maximum Subarray Approaches

| Approach | Time Complexity |
|---|---|
| Brute Force | O(n²) |
| Divide and Conquer | O(n log n) |
| Kadane's Algorithm | O(n) |

### Reason for Selection

Kadane's Algorithm provides the most efficient standard solution among these approaches and requires only one traversal of the activity sequence.

### Breaking News Application

The Maximum Subarray result represents the strongest sustained activity interval.

The application then uses a configurable threshold to classify whether this activity should be treated as a breaking-news event.

Topic identification and thresholding are application-level logic. Kadane's Algorithm itself only analyzes the numerical activity sequence.

---

## Activity Selection

### Purpose

Activity Selection is used to assign the maximum number of compatible newsroom tasks to a single reporter.

### Design Paradigm

**Greedy**

### Greedy Choice

Select the compatible activity having the **earliest finishing time**.

This leaves maximum remaining time for future tasks.

### Compatibility Condition

A new task can be assigned when:

`next.start >= previous.finish`

### Real-World Interpretation

An activity that conflicts with Reporter 1's schedule is **not deleted or cancelled**.

It remains unassigned to that reporter and can be assigned to another reporter.

### Complexity

Greedy selection after activities are sorted:

`O(n)`

The current prototype uses a simple nested-loop sorting helper:

`O(n²)`

Therefore the complete current implementation is:

`O(n²)`

For larger datasets, an O(n log n) sorting algorithm could reduce the total complexity.

---

## Huffman Coding

### Purpose

Huffman Coding demonstrates **lossless compression** of newsroom text such as headlines and article content.

Frequently occurring characters receive shorter binary codes, while less frequent characters receive longer codes.

### Design Paradigm

**Greedy**

### Data Structures

- Min-Heap
- Binary Huffman Tree

### Greedy Choice

Repeatedly select and combine the **two minimum-frequency nodes**.

### Working

1. Count character frequencies.
2. Create one node for each distinct character.
3. Build a Min-Heap using character frequencies.
4. Extract the two minimum-frequency nodes.
5. Combine them into a new internal node.
6. Insert the combined node back into the Min-Heap.
7. Repeat until one root remains.
8. Traverse the Huffman Tree using:
   - Left edge = 0
   - Right edge = 1

### Complexity

Let `k` be the number of distinct characters.

Using a Min-Heap, Huffman tree construction takes:

`O(k log k)`

### Compression Analysis

The prototype assumes the original text uses 8 bits per character.

Therefore:

`Original Size = Number of Characters × 8`

The encoded size is calculated by summing the lengths of the generated Huffman codes.

Space saving is calculated as:

`((Original Size - Encoded Size) / Original Size) × 100`

This calculation measures the encoded payload. A real compressed file would also need to store information required to reconstruct the Huffman tree or code table.

---

## Algorithm Design Paradigms Covered

### Divide and Conquer

- Merge Sort
- Quick Sort
- Binary Search

### Dynamic Programming

- Longest Common Subsequence

### Greedy

- Activity Selection
- Huffman Coding

### String Matching and Hashing

- Naive Pattern Matching
- Rabin-Karp

### Sequential Searching

- Linear Search

### Maximum Subarray Optimization

- Kadane's Algorithm

---

## Core Project Workflow

`articles.csv`

↓  

`Article Structures`

↓

**Article Organization**
- Merge Sort
- Quick Sort

↓

**Article Retrieval**
- Linear Search
- Binary Search

↓

**Headline Keyword Search**
- Naive Pattern Matching
- Rabin-Karp

↓

**Related Story Detection**
- LCS

↓

**Breaking News Activity Detection**
- Kadane's Algorithm

↓

**Reporter Task Scheduling**
- Greedy Activity Selection

↓

**Text Compression**
- Huffman Coding with Min-Heap

---

## Testing Strategy

The system is tested using normal cases and edge cases.

### Searching

- Existing Article ID
- Missing Article ID
- First and last Article IDs

### Sorting

- Random article order
- Already sorted input
- Equal priority values

### Pattern Matching

- Keyword present
- Keyword absent
- Pattern longer than headline
- Empty pattern

### Related Story Detection

- Similar headlines
- Unrelated headlines

### Breaking News Detection

- Positive and negative activity changes
- Sustained activity increase
- Activity below the breaking threshold

### Activity Selection

- Compatible tasks
- Overlapping tasks
- Tasks beginning exactly when another task finishes

### Huffman Coding

- Normal headline
- Repetitive characters
- Single distinct character
- Text containing spaces

---

## Limitations

- The project currently uses a small controlled CSV dataset.
- Article priority is pre-assigned editorial metadata.
- Basic keyword searching is case-sensitive.
- LCS measures textual sequence similarity rather than semantic meaning.
- The related-story threshold is manually configured.
- Breaking-news activity currently uses a prototype activity sequence.
- The system is not connected to a live news API.
- Activity Selection currently optimizes the schedule for one reporter at a time.
- Huffman compression statistics do not include the storage overhead of the Huffman tree/code table.

---

## Future Improvements

- Live news API integration
- Automatic article priority calculation
- Generate activity sequences dynamically from article timestamps
- Larger datasets for empirical algorithm benchmarking
- Case-insensitive and normalized keyword searching
- NLP-based semantic similarity in addition to LCS
- Multi-reporter scheduling using interval partitioning
- Persistent sorted indexes for repeated Binary Search
- Complete Huffman file encoding and decoding

---

## Conclusion

The **Newsroom Duplicate Story & Breaking Event Tracker** demonstrates how different DAA algorithms can solve different computational problems within a single practical application.

The core project features are:

- **LCS** for related-story detection
- **Kadane's Algorithm** for breaking-news activity detection

The supporting algorithms provide:

- Sorting and ranking
- Efficient article retrieval
- Keyword searching
- Reporter scheduling
- Lossless text compression

The project therefore demonstrates not only algorithm implementation, but also **algorithm selection, complexity analysis, comparison, modular design, and practical application in a common newsroom workflow**.