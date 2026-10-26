#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};
struct Node* createNode(char ch, int freq) {
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node* nodes[MAX];
int count = 0;
void insertNode(struct Node* node) {
    nodes[count++] = node;
}
struct Node* extractMin() {
    int i, minIndex = 0;
    for (i = 1; i < count; i++) {
        if (nodes[i]->freq < nodes[minIndex]->freq)
            minIndex = i;
    }
    struct Node* minNode = nodes[minIndex];
    for (i = minIndex; i < count - 1; i++)
        nodes[i] = nodes[i + 1];
    count--;
    return minNode;
}
void generateCodes(struct Node* root, char code[], int depth) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        printf("%c : %s\n", root->ch, code);
        return;
    }
    code[depth] = '0';
    generateCodes(root->left, code, depth + 1);
    code[depth] = '1';
    generateCodes(root->right, code, depth + 1);
}
int main() {
    int n, i, freq;
    char ch;
    char code[MAX];
    printf("Enter number of characters: ");
    scanf("%d", &n);
    printf("Enter character and frequency:\n");
    for (i = 0; i < n; i++) {
        scanf(" %c %d", &ch, &freq);
        insertNode(createNode(ch, freq));
    }
    while (count > 1) {
        struct Node* left = extractMin();
        struct Node* right = extractMin();
        struct Node* parent =
            createNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        insertNode(parent);
    }
    printf("\nHuffman Codes:\n");
    generateCodes(nodes[0], code, 0);
    return 0;
}