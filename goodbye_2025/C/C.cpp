#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long suffix_sum = 0;
    for (int i = 1; i < n; ++i) {
        suffix_sum += a[i];
    }
    long long max_x = -suffix_sum;
    long long prefix_abs = 0;
    for (int k = 1; k < n; ++k) {
        suffix_sum -= a[k];
        long long current_x = a[0] + prefix_abs - suffix_sum;
        if (current_x > max_x) {
            max_x = current_x;
        }
        prefix_abs += abs(a[k]);
    }

    cout << max_x << "\n";
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
