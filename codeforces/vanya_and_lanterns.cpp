#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000

int main() {
    int n, l;
    cin >> n >> l;
    double lanterns[MAX_N];
    double distance, max_distance;

    for (int i = 0; i < n; i++) cin >> lanterns[i];
    sort(lanterns, lanterns + n);

    max_distance = 2 * max(lanterns[0], l - lanterns[n-1]);
    for (int i = 0; i < n-1; i++) {
        distance = lanterns[i+1] - lanterns[i];
        max_distance = max(max_distance, distance);
    }

    printf("%.10f\n", max_distance / 2);

    return 0;
}
