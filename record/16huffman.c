/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 09/09/2026
EXPERIMENT NO: 16

ALGORITHM: Huffman Coding (Greedy Minimum Spanning Tree-style coding)
1. Create a leaf node for each unique character containing its frequency.
2. Build a Min-Priority Queue of all leaf nodes.
3. While there is more than one node in the queue:
 a. Extract the two nodes with the lowest frequency from min-heap (let them be left and right).
 b. Create a new internal node with frequency equal to sum of left and right frequencies.
 c. Set its left child to 'left' and right child to 'right'.
 d. Insert this new node back into the min-priority queue.
4. The remaining node in priority queue is the Root of the Huffman Tree.
5. Traverse the Huffman Tree from root, appending '0' for left branch and '1' for right branch to assign codes.
===================================================================
*/

/* 16. Implementation of Huffman algorithm */
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

struct MinTreeNode {
  char data;
  unsigned frequency;
  struct MinTreeNode *left, *right;
};

struct MinHeap {
  unsigned size;
  unsigned capacity;
  struct MinTreeNode** array;
};

struct MinTreeNode* createNode(char data, unsigned frequency) {
  struct MinTreeNode* node = (struct MinTreeNode*)malloc(sizeof(struct MinTreeNode));
  node->left = node->right = NULL;
  node->data = data;
  node->frequency = frequency;
  return node;
}

struct MinHeap* createMinHeap(unsigned capacity) {
  struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinTreeNode**)malloc(minHeap->capacity * sizeof(struct MinTreeNode*));
  return minHeap;
}

void swapMinTreeNode(struct MinTreeNode** a, struct MinTreeNode** b) {
  struct MinTreeNode* t = *a;
  *a = *b;
  *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
    smallest = left;

  if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
    smallest = right;

  if (smallest != idx) {
    swapMinTreeNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

int isSizeOne(struct MinHeap* minHeap) {
  return (minHeap->size == 1);
}

struct MinTreeNode* extractMin(struct MinHeap* minHeap) {
  struct MinTreeNode* temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];
  --minHeap->size;
  minHeapify(minHeap, 0);
  return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinTreeNode* minTreeNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && minTreeNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = minTreeNode;
}

void buildMinHeap(struct MinHeap* minHeap) {
  int n = minHeap->size - 1;
  for (int i = (n - 1) / 2; i >= 0; --i)
    minHeapify(minHeap, i);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
  struct MinHeap* minHeap = createMinHeap(size);
  for (int i = 0; i < size; ++i)
    minHeap->array[i] = createNode(data[i], freq[i]);
  minHeap->size = size;
  buildMinHeap(minHeap);
  return minHeap;
}

struct MinTreeNode* buildHuffmanTree(char data[], int freq[], int size) {
  struct MinTreeNode *left, *right, *top;
  struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

  while (!isSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);
    top = createNode('$', left->frequency + right->frequency);
    top->left = left;
    top->right = right;
    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

void printCodes(struct MinTreeNode* root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }
  if (root->right) {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }
  if (!(root->left) && !(root->right)) {
    printf("%c: ", root->data);
    for (int i = 0; i < top; ++i)
      printf("%d", arr[i]);
    printf("\n");
  }
}

void HuffmanCodes(char data[], int freq[], int size) {
  struct MinTreeNode* root = buildHuffmanTree(data, freq, size);
  int arr[MAX_TREE_HT], top = 0;
  printCodes(root, arr, top);
}

int main() {
  char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Huffman Codes:\n");
  HuffmanCodes(arr, freq, size);
  return 0;
}
