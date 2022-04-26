#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node_t ;

void print_list(node_t *head) {
    node_t *node = head;
    while (node) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("()\n");
}

node_t *new_node(int value) {
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

void insert_head(node_t **head, node_t *to_insert) {
    to_insert->next = *head;
    *head = to_insert;
}

void insert_last(node_t **head, node_t *to_insert) {
    node_t *node = *head;
    if (!node) *head = to_insert;
    while (node->next) node = node->next;
    node->next = to_insert;
}

node_t *find_node(node_t *head, int value) {
    node_t *node = head;
    while (node != NULL) {
        if (node->value == value) return node;
        node = node->next;
    }
    return NULL;
}

void remove_head(node_t **head) {
    *head = (*head)->next;
}

void remove_last(node_t **head) {
    node_t *node = *head;
    while (node->next->next) node = node->next;
    node->next = NULL;
}

int main(int argc, char *argv[]) {
    node_t *node;
    node_t *head = NULL;

    for (int i = 0; i <= 11; i++) {
        node = new_node(i);
        insert_head(&head, node);
    }
    for (int i = 11; i <= 21; i++) {
        node = new_node(i);
        insert_last(&head, node);
    }
    node = find_node(head, 8);
    printf("Found node with value %d\n", node->value);
    remove_head(&head);
    remove_last(&head);
    print_list(head);

    return 0;
}
