#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int length;
    int max_length;
    int* p;
} dynamic_array;

dynamic_array *create_array(int length) {
    dynamic_array *arr = malloc(sizeof(dynamic_array));
    arr->length = length;
    arr->max_length = 2 * length;
    arr->p = calloc(arr->max_length, sizeof(int));
    return arr;
}

void  insert_element(dynamic_array *arr, int value) {
    arr->length++;
    if (arr->length > arr->max_length) {
        arr->max_length *= 2;
        arr->p = reallocarray(arr->p, arr->max_length, sizeof(int));
    }
    arr->p[arr->length-1] = value;
}

void printarray(dynamic_array *arr) {
    for (int i = 0; i < arr->length; i++)
        printf("%d ", arr->p[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int length = 1;
    dynamic_array *arr = create_array(length);
    for (int i = 1; i <= 10; i++) {
        insert_element(arr, i);
        printarray(arr);
    }
    free(arr->p);
    free(arr);
    return 0;
}
