#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define vll vector<ll>
#define pll pair<ll, ll>
#define endl '\n'
#define MA9ROUNA_KADHEBA                                                       \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);

const int MOD = 1000000007;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}
ll modpow(ll a, ll e, ll mod = MOD) {
    ll r = 1;
    while (e) {
        if (e & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}

void solve() {
    int n;
    ll ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vll x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    map<int, pair<ll, ll>> stages;
    for (int i = 0; i < n; i++) {
        if (stages.find(x[i]) == stages.end()) {
            stages[x[i]] = {y[i], y[i]};
        } else {
            stages[x[i]].first = min(stages[x[i]].first, y[i]);
            stages[x[i]].second = max(stages[x[i]].second, y[i]);
        }
    }
    ll prev_y_min = ay;
    ll prev_y_max = ay;
    ll dp_min = 0;
    ll dp_max = 0;
    for (auto const& [curr_x, range] : stages) {
        ll curr_min = range.first;
        ll curr_max = range.second;
        ll dist_internal = curr_max - curr_min;
        ll from_prev_min_to_min = dp_min + abs(prev_y_min - curr_max) + dist_internal;
        ll from_prev_max_to_min = dp_max + abs(prev_y_max - curr_max) + dist_internal;
        ll next_dp_min = min(from_prev_min_to_min, from_prev_max_to_min);
        ll from_prev_min_to_max = dp_min + abs(prev_y_min - curr_min) + dist_internal;
        ll from_prev_max_to_max = dp_max + abs(prev_y_max - curr_min) + dist_internal;
        ll next_dp_max = min(from_prev_min_to_max, from_prev_max_to_max);
        dp_min = next_dp_min;
        dp_max = next_dp_max;
        prev_y_min = curr_min;
        prev_y_max = curr_max;
    }
    ll final_from_min = dp_min + abs(prev_y_min - by);
    ll final_from_max = dp_max + abs(prev_y_max - by);
    ll total_vertical = min(final_from_min, final_from_max);
    ll total_horizontal = bx - ax;
    ll ans = total_horizontal + total_vertical;
    cout << ans % MOD << endl;
}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        // cout << '\n';
    }
    return 0;
}
