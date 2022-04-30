#include <bits/stdc++.h>

using namespace std;

bool binary_search(int *a, int i, int j, int value) {
    if (j < i) return false;
    int m = (i + j) / 2;
    if (a[m] == value) return true;
    if (a[m] < value) return binary_search(a, m+1, j, value);
    return binary_search(a, i, m-1, value);
}

int main() {
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int length = sizeof(arr) / sizeof(int);
    sort(arr, arr + length);

    int value = 2;
    bool found = binary_search(arr, 0, length, value);
    if (found) cout << "Found " << value << " in the array" << endl;
    else cout << value << " wasn't found in the array";

    return 0;
}
