#include <bits/stdc++.h>

using namespace std;

int main() {
    long long p, m, M, c, n, count_m, count_M;
    m = INT_MAX;
    M = -1;
    count_m = count_M = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == m) count_m++;
        if (c == M) count_M++;
        if (c < m) {
            m = c;
            count_m = 1;
        }
        if (c > M) {
            M = c;
            count_M = 1;
        }
    }

    if (m == M) {
        p = n * (n - 1) / 2;
    } else {
        p = count_m * count_M;
    }

    cout << M - m << " " << p;

    return 0;
}
