#include <iostream>
#include <string>
#include <vector>
#include <cassert> 
using namespace std;

void solve() {
    string r;
    cin >> r;
    int n = r.length();
    for (char c : r) {
        assert(c == 's' || c == 'u');
    }
    int ops = 0;
    if (r[0] == 'u') {
        r[0] = 's';
        ops++;
    }
    if (r[n - 1] == 'u') {
        r[n - 1] = 's';
        ops++;
    }
    int current_u_run = 0;
    for (int i = 0; i < n; i++) {
        if (r[i] == 'u') {
            current_u_run++;
        } else {
            ops += current_u_run / 2;
            current_u_run = 0;
        }
    }
    cout << ops << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
