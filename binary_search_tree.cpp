#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *right;
    struct node *left;
} node_t;

node_t *createnode(int value) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool insert(node_t **rootptr, int value) {
    if (*rootptr == NULL) {
        *rootptr = createnode(value);
        return true;
    }
    if ((*rootptr)->value == value) return false;
    if (value < (*rootptr)->value) return insert(&((*rootptr)->left), value);
    return insert(&((*rootptr)->right), value);
}

bool find(node_t *root, int value) {
    if (root == NULL) return false;
    if (root->value == value) return true;
    if (root->value >= value) return find(root->left, value);
    return find(root->right, value);
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
    node_t *root = NULL;
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 20);
    printtree(root);
    bool found = find(root, 20);
    if (found) printf("Found!\n");
    else printf("Not found.\n");
    found = find(root, 21);
    if (found) printf("Found!\n");
    else printf("Not found.\n");

    return 0;
}
