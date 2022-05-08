#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c, r, k, res = 0;
    cin >> n >> a >> b >> c;
    for (int i = 0; i*a <= n; i++) {
        for (int j = 0; i*a+j*b <= n; j++) {
            r = n - i*a - j*b;
            if (r % c == 0) {
                k = r / c;
                res = max(res, i + j + k);
            }
        }
    }

    cout << res << endl;

    return 0;
}
