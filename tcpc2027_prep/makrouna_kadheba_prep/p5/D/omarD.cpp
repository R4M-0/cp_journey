#include <bits/stdc++.h>
using namespace std;

typedef struct connection {
    int id;
    int next; // ID of the next member in the 9:00 list (-1 if last)
    int idx;  // position of this member in the 9:00 list (used as p[id])
} connection;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // p[id] = position of member id in the 9:00 list
    vector<connection> conn(n + 1);
    for (int i = 0; i < n; i++) {
        conn[a[i]].id   = a[i];
        conn[a[i]].next = (i + 1 < n) ? a[i + 1] : -1;
        conn[a[i]].idx  = i;
    }

    // Non-online members form a suffix of b that is a subsequence of a.
    // A suffix b[r..n-1] is valid iff p[b[r]] < p[b[r+1]] < ... < p[b[n-1]].
    // Find the longest such suffix: scan right-to-left, stop at first violation
    // where p[b[i]] < p[b[i-1]] (b[i-1] must have been online).
    int r = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (conn[b[i]].idx < conn[b[i - 1]].idx) {
            r = i;
            break;
        }
    }

    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
