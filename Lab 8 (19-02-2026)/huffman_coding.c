#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

// Huffman Tree Node
struct Node{
    char data;
    int freq;
    struct Node *left, *right;
};

// Create new node
struct Node *newNode(char data, int freq){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Find two minimum frequency nodes
void findTwoMin(struct Node *arr[], int size, int *min1, int *min2){
    *min1 = 0;
    *min2 = 1;
    if (arr[*min1]->freq > arr[*min2]->freq){
        int temp = *min1;
        *min1 = *min2;
        *min2 = temp;
    }

    for (int i = 2; i < size; i++){
        if (arr[i]->freq < arr[*min1]->freq){
            *min2 = *min1;
            *min1 = i;
        }
        else if (arr[i]->freq < arr[*min2]->freq){
            *min2 = i;
        }
    }
}

// Print Huffman Codes
void printCodes(struct Node *root, int arr[], int top){
    if (root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right){
        printf("%c : ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main(){
    char text[] = "Data Analytics and Intelligence Laboratory";
    int freq[MAX] = {0};

    // Count frequency
    for (int i = 0; text[i] != '\0'; i++){
        freq[(int)text[i]]++;
    }

    struct Node *nodes[MAX];
    int size = 0;

    // Create nodes for each character
    for (int i = 0; i < MAX; i++){
        if (freq[i] > 0){
            nodes[size++] = newNode((char)i, freq[i]);
        }
    }

    // Build Huffman Tree
    while (size > 1){
        int min1, min2;
        findTwoMin(nodes, size, &min1, &min2);
        struct Node *left = nodes[min1];
        struct Node *right = nodes[min2];
        struct Node *new = newNode('$', left->freq + right->freq);
        new->left = left;
        new->right = right;
        if (min1 > min2){
            nodes[min1] = nodes[size - 1];
            nodes[min2] = new;
        }
        else{
            nodes[min2] = nodes[size - 1];
            nodes[min1] = new;
        }

        size--;
    }

    int arr[MAX], top = 0;
    printf("Huffman Codes:\n");
    printCodes(nodes[0], arr, top);

    return 0;
}