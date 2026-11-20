#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"

typedef struct HuffmanNode
{
    char character;
    int frequency;

    struct HuffmanNode *left;
    struct HuffmanNode *right;

} HuffmanNode;

HuffmanNode *createHuffmanNode(
    char character,
    int frequency
)
{
    HuffmanNode *node =
        (HuffmanNode *)
        malloc(sizeof(HuffmanNode));

    node->character = character;
    node->frequency = frequency;

    node->left = NULL;
    node->right = NULL;

    return node;
}

HuffmanNode *buildHuffmanTree(
    int frequency[]
)
{
    HuffmanNode *nodes[256];

    int count = 0;

    for (int i = 0; i < 256; i++)
    {
        if (frequency[i] > 0)
        {
            nodes[count++] =
                createHuffmanNode(
                    (char)i,
                    frequency[i]
                );
        }
    }

    if (count == 0)
    {
        return NULL;
    }

    while (count > 1)
    {
        int min1 = 0;

        for (int i = 1; i < count; i++)
        {
            if (nodes[i]->frequency <
                nodes[min1]->frequency)
            {
                min1 = i;
            }
        }

        HuffmanNode *left =
            nodes[min1];

        nodes[min1] =
            nodes[count - 1];

        count--;


        int min2 = 0;

        for (int i = 1; i < count; i++)
        {
            if (nodes[i]->frequency <
                nodes[min2]->frequency)
            {
                min2 = i;
            }
        }

        HuffmanNode *right =
            nodes[min2];

        nodes[min2] =
            nodes[count - 1];

        count--;


        HuffmanNode *parent =
            createHuffmanNode(
                '\0',
                left->frequency +
                right->frequency
            );

        parent->left = left;
        parent->right = right;

        nodes[count++] = parent;
    }

    return nodes[0];
}

void printHuffmanCodes(
    HuffmanNode *root,
    int code[],
    int depth,
    int *compressedBits
)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL &&
        root->right == NULL)
    {
        printf(
            "'%c' : ",
            root->character
        );

        for (int i = 0; i < depth; i++)
        {
            printf("%d", code[i]);
        }

        printf("\n");

        *compressedBits +=
            root->frequency * depth;

        return;
    }

    code[depth] = 0;

    printHuffmanCodes(
        root->left,
        code,
        depth + 1,
        compressedBits
    );

    code[depth] = 1;

    printHuffmanCodes(
        root->right,
        code,
        depth + 1,
        compressedBits
    );
}

void freeHuffmanTree(
    HuffmanNode *root
)
{
    if (root == NULL)
    {
        return;
    }

    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);

    free(root);
}

void huffmanDemo()
{
    char text[500];

    printf(
        "\nEnter headline/text to compress: "
    );

    getchar();

    fgets(
        text,
        sizeof(text),
        stdin
    );

    text[strcspn(text, "\n")] = '\0';

    int frequency[256] = {0};

    for (int i = 0; text[i] != '\0'; i++)
    {
        frequency[
            (unsigned char)text[i]
        ]++;
    }

    HuffmanNode *root =
        buildHuffmanTree(
            frequency
        );

    if (root == NULL)
    {
        printf(
            "\nNo text entered.\n"
        );

        return;
    }

    printf("\n===== HUFFMAN CODES =====\n\n");

    int code[256];

    int compressedBits = 0;

    if (root->left == NULL &&
        root->right == NULL)
    {
        printf(
            "'%c' : 0\n",
            root->character
        );

        compressedBits =
            root->frequency;
    }
    else
    {
        printHuffmanCodes(
            root,
            code,
            0,
            &compressedBits
        );
    }

    int originalBits =
        strlen(text) * 8;

    printf(
        "\nOriginal Size: %d bits\n",
        originalBits
    );

    printf(
        "Compressed Size: %d bits\n",
        compressedBits
    );

    if (originalBits > 0)
    {
        double saving =
            100.0 *
            (originalBits - compressedBits) /
            originalBits;

        printf(
            "Approximate Saving: %.2f%%\n",
            saving
        );
    }

    freeHuffmanTree(root);
}