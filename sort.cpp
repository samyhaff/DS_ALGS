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

void merge(int *arr, int l, int m, int r) {
    int len_left = m - l + 1;
    int len_right = r - m;
    int left[len_left];
    int right[len_right];

    int i, j, k;
    for (i = 0; i < len_left; i++)
        left[i] = arr[l + i];
    for (i = 0; i < len_right; i++)
        right[i] = arr[m + i + 1];

    i = 0; j = 0;
    for (k = l; k < r; k++) {
        if (i >= len_left) {
            arr[k] = right[j];
            j++;
        }
        if (j >= len_right) {
            arr[k] = left[i];
            i++;
        }
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }
}

void mergesort(int *arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(int);
    mergesort(arr, 0, n);
    printarray(arr, n);

    return 0;
}
