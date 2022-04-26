#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define TABLE_SIZE 10

typedef struct node {
    char value[MAX_LENGTH];
    struct node *next;
} node_t;

node_t *hash_table[TABLE_SIZE];

void hash_table_print() {
    for (int i=0; i < TABLE_SIZE; i++) {
        printf("%d: ", i);
        node_t *node = hash_table[i];
        while (node) {
            printf("%s -> ", node->value);
            node = node->next;
        }
        printf("()\n");
    }
}

unsigned int hash(char *value) {
    int length = strnlen(value, MAX_LENGTH);
    unsigned int hash_value = 0;
    for (int i=0; i < length; i++) {
        hash_value += value[i];
    }
    hash_value = hash_value % TABLE_SIZE;
    return hash_value;
}

void hash_table_insert(node_t *node) {
    char *value = node->value;
    int idx = hash(value);
    node-> next = hash_table[idx];
    hash_table[idx] = node;
}

void init_table() {
    for (int i=0; i < TABLE_SIZE; i++)
        hash_table[i] = NULL;
}

node_t *hash_table_lookup(char *value) {
    int idx = hash(value);
    node_t *node = hash_table[idx];
    while (node) {
        if (strncmp(node->value, value, MAX_LENGTH) == 0) return node;
        node = node->next;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    init_table();
    node_t node1 = {.value = "test", .next = NULL};
    node_t node2 = {.value = "abc", .next = NULL};
    node_t node3 = {.value = "hello", .next = NULL};
    hash_table_insert(&node1);
    hash_table_insert(&node2);
    hash_table_insert(&node3);
    hash_table_print();
    node_t *tmp = hash_table_lookup("test");
    if (tmp) printf("Found node\n");
    else printf("Node not found\n");

    return 0;
}
