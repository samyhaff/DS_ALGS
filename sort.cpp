#include <bits/stdc++.h>

using namespace std;

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void insertionsort(int *arr, int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            swap(arr, j, j-1);
            j--;
        }
    }
}

void printarray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(int);
    insertionsort(arr, n);
    printarray(arr, n);

    return 0;
}
