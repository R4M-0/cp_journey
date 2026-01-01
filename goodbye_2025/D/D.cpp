#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Elf {
    long long a;
    int id;
};

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<Elf> elves(n);
    for (int i = 0; i < n; ++i) {
        cin >> elves[i].a;
        elves[i].id = i + 1;
    }

    sort(elves.begin(), elves.end(), [](const Elf& x, const Elf& y) {
        return x.a < y.a;
    });

    vector<pair<int, int>> ops;
    if (m == 0) {
        long long total_sum = 0;
        for(int i = 0; i < n - 1; ++i) total_sum += elves[i].a;
        
        if (total_sum < elves[n-1].a) {
            cout << -1 << "\n";
            return;
        }
        long long current_sum = 0;
        int k = -1;
        for (int i = n - 2; i >= 0; --i) {
            current_sum += elves[i].a;
            if (current_sum >= elves[n-1].a) {
                k = i;
                break;
            }
        }
        
        for (int i = 0; i < k; ++i) {
            ops.push_back({elves[i].id, elves[i+1].id});
        }
        
        for (int i = k + 1; i <= n - 2; ++i) {
            ops.push_back({elves[i].id, elves[n-1].id});
        }
        ops.push_back({elves[k].id, elves[n-1].id});
    } else if (m == 1) {
        for (int i = 0; i < n - 1; ++i) {
            ops.push_back({elves[i].id, elves[i+1].id});
        }
    } else {
        if (2 * m > n) {
            cout << -1 << "\n";
            return;
        }
        for (int i = 0; i < n - 2 * m; ++i) {
             ops.push_back({elves[i].id, elves[i+1].id});
        }
        for (int i = 0; i < m; ++i) {
            int victim_idx = n - 2 * m + i;
            int survivor_idx = n - m + i;
            ops.push_back({elves[survivor_idx].id, elves[victim_idx].id});
        }
    }

    cout << ops.size() << "\n";
    for (auto p : ops) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
