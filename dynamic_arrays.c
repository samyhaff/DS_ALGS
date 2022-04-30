#include <stdio.h>
#include <stdlib.h>

void printarray(int *array, int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s length\n", argv[0]);
        exit(1);
    }
    int length = atoi(argv[1]);
    int *p = malloc(sizeof(int) * length);
    for (int i=0; i < length; i++)
        p[i] = i;
    printarray(p, length);
    free(p);
    return 0;
}
