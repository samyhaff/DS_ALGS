#include <bits/stdc++.h>

using namespace std;

#define N_MAX 100000

int main() {
    int n, l = 0, r = 0;
    int arr[N_MAX];
    bool flag = false;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i+1]) {
            l = i;
            break;
        }
    }

    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i-1]) {
            r = i;
            break;
        }
    }

    reverse(arr + l, arr + r + 1);
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i+1]) flag = true;

    if (flag) cout << "no" << endl;
    else cout << "yes" << endl << l+1 << " " << r+1 << endl;

    return 0;
}
