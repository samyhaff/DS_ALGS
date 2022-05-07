#include <bits/stdc++.h>

#define MAX_N 100
enum {EVEN, ODD};

using namespace std;

int get_index() {
    int n, numbers[MAX_N];
    bool evenness;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> numbers[i];
    int a_evenness = numbers[0] % 2;
    int b_evenness = numbers[1] % 2;
    int c_evenness = numbers[2] % 2;

    evenness = (a_evenness + b_evenness + c_evenness >= 2) ? ODD : EVEN;

    if (a_evenness != evenness) return 1;
    if (b_evenness != evenness) return 2;
    if (c_evenness != evenness) return 3;

    for (int i = 3; i < n; i++) {
        if (numbers[i] % 2 != evenness) return i + 1;
    }

    return -1;
}

int main() {
    int idx = get_index();
    cout << idx << endl;

    return 0;
}
