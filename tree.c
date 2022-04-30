#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *right;
    struct node *left;
} node_t;

node_t *createnode(int value) {
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printlevel(int count) {
    for (int i = 0; i < count; i++)
        printf("-");
}

void printtreerec(node_t *node, int depth) {
    if (node == NULL) {
        printlevel(depth);
        printf("()\n");
        return;
    }
    printlevel(depth);
    printf("%d\n", node->value);
    printtreerec(node->left, depth+1);
    printtreerec(node->right, depth+1);
}

void printtree(node_t *node) {
    printtreerec(node, 0);
}

int main(int argc, char *argv[]) {
    node_t *n1 = createnode(1);
    node_t *n2 = createnode(2);
    node_t *n3 = createnode(3);
    n1->right = n2;
    n1->left = n3;
    printtree(n1);

    return 0;
}
