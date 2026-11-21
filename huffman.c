#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"

#define MAX_CHARACTERS 256
#define MAX_CODE_LENGTH 256


// Huffman Tree Node
typedef struct HuffmanNode
{
    char character;
    int frequency;

    struct HuffmanNode *left;
    struct HuffmanNode *right;

} HuffmanNode;


// Min Heap
typedef struct
{
    int size;
    int capacity;

    HuffmanNode **array;

} MinHeap;


// Create a new Huffman node
HuffmanNode *createNode(char character, int frequency)
{
    HuffmanNode *node =
        (HuffmanNode *)malloc(sizeof(HuffmanNode));

    node->character = character;
    node->frequency = frequency;

    node->left = NULL;
    node->right = NULL;

    return node;
}


// Create a Min Heap
MinHeap *createMinHeap(int capacity)
{
    MinHeap *heap =
        (MinHeap *)malloc(sizeof(MinHeap));

    heap->size = 0;
    heap->capacity = capacity;

    heap->array =
        (HuffmanNode **)malloc(
            capacity * sizeof(HuffmanNode *)
        );

    return heap;
}


// Swap two Huffman nodes
void swapNodes(
    HuffmanNode **a,
    HuffmanNode **b
)
{
    HuffmanNode *temp = *a;

    *a = *b;
    *b = temp;
}


// Maintain Min-Heap property
void minHeapify(
    MinHeap *heap,
    int index
)
{
    int smallest = index;

    int left = 2 * index + 1;
    int right = 2 * index + 2;


    if (left < heap->size &&
        heap->array[left]->frequency <
        heap->array[smallest]->frequency)
    {
        smallest = left;
    }


    if (right < heap->size &&
        heap->array[right]->frequency <
        heap->array[smallest]->frequency)
    {
        smallest = right;
    }


    if (smallest != index)
    {
        swapNodes(
            &heap->array[index],
            &heap->array[smallest]
        );

        minHeapify(
            heap,
            smallest
        );
    }
}


// Extract minimum-frequency node
HuffmanNode *extractMin(MinHeap *heap)
{
    if (heap->size == 0)
    {
        return NULL;
    }


    HuffmanNode *minimum =
        heap->array[0];


    heap->array[0] =
        heap->array[heap->size - 1];


    heap->size--;


    if (heap->size > 0)
    {
        minHeapify(
            heap,
            0
        );
    }


    return minimum;
}


// Insert node into Min Heap
void insertMinHeap(
    MinHeap *heap,
    HuffmanNode *node
)
{
    heap->size++;

    int i = heap->size - 1;


    while (i > 0 &&
           node->frequency <
           heap->array[(i - 1) / 2]->frequency)
    {
        heap->array[i] =
            heap->array[(i - 1) / 2];

        i = (i - 1) / 2;
    }


    heap->array[i] = node;
}


// Build Min Heap
void buildMinHeap(MinHeap *heap)
{
    int start =
        (heap->size - 2) / 2;


    for (int i = start; i >= 0; i--)
    {
        minHeapify(
            heap,
            i
        );
    }
}


// Check whether node is a leaf
int isLeaf(HuffmanNode *node)
{
    return (
        node->left == NULL &&
        node->right == NULL
    );
}


// Build Huffman Tree using Min Heap
HuffmanNode *buildHuffmanTree(
    char characters[],
    int frequencies[],
    int size
)
{
    MinHeap *heap =
        createMinHeap(size);


    for (int i = 0; i < size; i++)
    {
        heap->array[i] =
            createNode(
                characters[i],
                frequencies[i]
            );
    }


    heap->size = size;

    buildMinHeap(heap);


    while (heap->size > 1)
    {
        // Greedy choice: take two minimum-frequency nodes
        HuffmanNode *left =
            extractMin(heap);

        HuffmanNode *right =
            extractMin(heap);


        // Combine their frequencies
        HuffmanNode *combined =
            createNode(
                '\0',
                left->frequency +
                right->frequency
            );


        combined->left = left;
        combined->right = right;


        // Insert combined node back into Min Heap
        insertMinHeap(
            heap,
            combined
        );
    }


    HuffmanNode *root =
        extractMin(heap);


    free(heap->array);
    free(heap);


    return root;
}


// Generate Huffman codes and store them
void generateCodes(
    HuffmanNode *root,
    int code[],
    int top,
    char huffmanCodes[MAX_CHARACTERS][MAX_CODE_LENGTH]
)
{
    if (root == NULL)
    {
        return;
    }


    // Left edge = 0
    if (root->left != NULL)
    {
        code[top] = 0;

        generateCodes(
            root->left,
            code,
            top + 1,
            huffmanCodes
        );
    }


    // Right edge = 1
    if (root->right != NULL)
    {
        code[top] = 1;

        generateCodes(
            root->right,
            code,
            top + 1,
            huffmanCodes
        );
    }


    // Leaf node contains actual character
    if (isLeaf(root))
    {
        unsigned char ch =
            (unsigned char)root->character;


        // Special case when input contains only one unique character
        if (top == 0)
        {
            huffmanCodes[ch][0] = '0';
            huffmanCodes[ch][1] = '\0';
        }
        else
        {
            for (int i = 0; i < top; i++)
            {
                huffmanCodes[ch][i] =
                    code[i] + '0';
            }

            huffmanCodes[ch][top] =
                '\0';
        }
    }
}


// Free Huffman Tree
void freeHuffmanTree(HuffmanNode *root)
{
    if (root == NULL)
    {
        return;
    }


    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);

    free(root);
}


// Huffman Coding demonstration
void huffmanDemo()
{
    char text[500];


    printf("\n");
    printf("============================================================\n");
    printf("                   HUFFMAN COMPRESSION\n");
    printf("============================================================\n");


    printf("\nEnter article headline/text: ");

    scanf(
        " %499[^\n]",
        text
    );


    // Count character frequencies
    int frequency[MAX_CHARACTERS] = {0};


    for (int i = 0; text[i] != '\0'; i++)
    {
        unsigned char ch =
            (unsigned char)text[i];

        frequency[ch]++;
    }


    // Store unique characters
    char characters[MAX_CHARACTERS];

    int frequencies[MAX_CHARACTERS];

    int uniqueCount = 0;


    for (int i = 0; i < MAX_CHARACTERS; i++)
    {
        if (frequency[i] > 0)
        {
            characters[uniqueCount] =
                (char)i;

            frequencies[uniqueCount] =
                frequency[i];

            uniqueCount++;
        }
    }


    if (uniqueCount == 0)
    {
        printf("\nNo text entered.\n");
        return;
    }


    // Display character frequencies
    printf("\nCHARACTER FREQUENCIES\n");
    printf("------------------------------------------------------------\n");


    for (int i = 0; i < uniqueCount; i++)
    {
        if (characters[i] == ' ')
        {
            printf(
                "SPACE : %d\n",
                frequencies[i]
            );
        }
        else
        {
            printf(
                "%c     : %d\n",
                characters[i],
                frequencies[i]
            );
        }
    }


    // Build Huffman Tree using Min Heap
    HuffmanNode *root =
        buildHuffmanTree(
            characters,
            frequencies,
            uniqueCount
        );


    // Store Huffman codes for every character
    char huffmanCodes[MAX_CHARACTERS][MAX_CODE_LENGTH] = {{0}};

    int code[MAX_CODE_LENGTH];


    generateCodes(
        root,
        code,
        0,
        huffmanCodes
    );


    // Display Huffman codes
    printf("\nHUFFMAN CODES\n");
    printf("------------------------------------------------------------\n");

    printf("Left Edge  = 0\n");
    printf("Right Edge = 1\n\n");


    for (int i = 0; i < uniqueCount; i++)
    {
        unsigned char ch =
            (unsigned char)characters[i];


        if (characters[i] == ' ')
        {
            printf(
                "'SPACE' : %-12s (frequency = %d)\n",
                huffmanCodes[ch],
                frequencies[i]
            );
        }
        else
        {
            printf(
                "'%c'     : %-12s (frequency = %d)\n",
                characters[i],
                huffmanCodes[ch],
                frequencies[i]
            );
        }
    }


    // Display original text
    printf("\nORIGINAL TEXT\n");
    printf("------------------------------------------------------------\n");

    printf("%s\n", text);


    // Display encoded text
    printf("\nHUFFMAN ENCODED TEXT\n");
    printf("------------------------------------------------------------\n");


    int encodedBits = 0;


    for (int i = 0; text[i] != '\0'; i++)
    {
        unsigned char ch =
            (unsigned char)text[i];


        printf(
            "%s",
            huffmanCodes[ch]
        );


        encodedBits +=
            strlen(huffmanCodes[ch]);
    }


    printf("\n");


    // Calculate original size
    int originalBits =
        strlen(text) * 8;


    // Calculate number of bits saved
    int bitsSaved =
        originalBits - encodedBits;


    // Calculate compression percentage
    double spaceSaved = 0.0;


    if (originalBits > 0)
    {
        spaceSaved =
            ((double)bitsSaved /
             originalBits) * 100.0;
    }


    // Display compression analysis
    printf("\nCOMPRESSION ANALYSIS\n");
    printf("------------------------------------------------------------\n");


    printf(
        "Original Size   : %d bits\n",
        originalBits
    );


    printf(
        "Encoded Size    : %d bits\n",
        encodedBits
    );


    printf(
        "Bits Saved      : %d bits\n",
        bitsSaved
    );


    printf(
        "Space Saved     : %.2f%%\n",
        spaceSaved
    );


    printf("\n");
    printf("Algorithm       : Huffman Coding\n");
    printf("Paradigm        : Greedy\n");
    printf("Data Structure  : Min-Heap + Binary Tree\n");
    printf("Greedy Choice   : Combine two minimum-frequency nodes\n");


    printf("============================================================\n");


    freeHuffmanTree(root);
}