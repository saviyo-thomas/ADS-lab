/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 13/07/2026
EXPERIMENT NO: 05

ALGORITHM: Huffman Coding (Data Compression) with Sorted Output
1. Read the input string and compute the frequency of each unique character using a frequency map.
2. Create a leaf node for each unique character containing its character and frequency, and build a Min-Heap of these nodes.
3. Repeat the following steps while the size of the Min-Heap is greater than 1:
   a. Extract the two nodes with the minimum frequencies from the Min-Heap.
   b. Create a new internal node with a special character (e.g., '$') and a frequency equal to the sum of the two extracted nodes' frequencies.
   c. Set the left child of the new node to the first extracted node and the right child to the second extracted node.
   d. Insert the newly created internal node back into the Min-Heap.
4. The last remaining node in the Min-Heap becomes the root of the Huffman Tree.
5. Traverse the Huffman Tree recursively to collect all leaf nodes along with their binary Huffman codes.
6. Sort the collected entries in descending order of frequency (highest frequency at the top, lowest frequency at the bottom).
7. Print the final sorted table containing characters, frequencies, and their Huffman codes.
===================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100
#define MAX_STR_LEN 1000
#define ASCII_SIZE 256

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

struct CodeEntry {
    char data;
    unsigned freq;
    int code[MAX_TREE_HT];
    int code_len;
};

struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Recursively collect all leaf nodes and their codes into an array
void collectCodes(struct MinHeapNode* root, int arr[], int top, struct CodeEntry entries[], int *count) {
    if (root->left) {
        arr[top] = 0;
        collectCodes(root->left, arr, top + 1, entries, count);
    }
    if (root->right) {
        arr[top] = 1;
        collectCodes(root->right, arr, top + 1, entries, count);
    }
    if (isLeaf(root)) {
        entries[*count].data = root->data;
        entries[*count].freq = root->freq;
        entries[*count].code_len = top;
        for (int i = 0; i < top; i++) {
            entries[*count].code[i] = arr[i];
        }
        (*count)++;
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    
    struct CodeEntry entries[ASCII_SIZE];
    int count = 0;
    
    collectCodes(root, arr, top, entries, &count);
    
    // Sort entries in descending order of frequency (highest freq at top, lowest at bottom)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (entries[j].freq < entries[j + 1].freq) {
                struct CodeEntry temp = entries[j];
                entries[j] = entries[j + 1];
                entries[j + 1] = temp;
            }
        }
    }
    
    printf("\nChar  |  Freq  |  Huffman Code\n");
    printf("-----------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("  %c   |   %2d   |   ", entries[i].data, entries[i].freq);
        for (int j = 0; j < entries[i].code_len; j++) {
            printf("%d", entries[i].code[j]);
        }
        printf("\n");
    }
}

int main() {
    char str[MAX_STR_LEN];
    int freq_map[ASCII_SIZE] = {0};

    printf("Enter the input string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("Empty string entered.\n");
        return 1;
    }

    // Calculate frequency of each unique character
    for (size_t i = 0; i < len; i++) {
        freq_map[(unsigned char)str[i]]++;
    }

    // Count unique characters
    int unique_count = 0;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (freq_map[i] > 0) {
            unique_count++;
        }
    }

    char* arr = (char*)malloc(unique_count * sizeof(char));
    int* freq = (int*)malloc(unique_count * sizeof(int));

    int index = 0;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (freq_map[i] > 0) {
            arr[index] = (char)i;
            freq[index] = freq_map[i];
            index++;
        }
    }

    HuffmanCodes(arr, freq, unique_count);

    free(arr);
    free(freq);
    return 0;
}
/*
   ===================================================================

   OUTPUT

   CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

   Enter the input string: never gonna give you up

   Char  |  Freq  |  Huffman Code
   -----------------------------
         |    4   |   00
     n   |    3   |   011
     e   |    3   |   101
     o   |    2   |   010
     v   |    2   |   1100
     u   |    2   |   1101
     g   |    2   |   1111
     y   |    1   |   1000
     r   |    1   |   10010
     i   |    1   |   10011
     a   |    1   |   11100
     p   |    1   |   11101
*/
