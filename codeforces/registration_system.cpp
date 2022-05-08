# include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;
    cin >> n;
    string user;
    map<string,int> users;

    for (int i = 0; i < n; i++) {
        cin >> user;
        users[user]++;
        if (users[user] == 1) {
            cout << "OK" << endl;
        } else
            cout << user + to_string(users[user] - 1) << endl;
    }

    return 0;
}
