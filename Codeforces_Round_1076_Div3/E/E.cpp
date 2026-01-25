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
    cin >> n;
    vector<int> a(n);
    vector<int> distinct_elements;
    vector<bool> present(n + 1, false);
    bool has_one = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            has_one = true;
        } else {
            if (!present[a[i]]) {
                distinct_elements.push_back(a[i]);
                present[a[i]] = true;
            }
        }
    }
    sort(all(distinct_elements));
    vector<int> dist(n + 1, -1);
    queue<int> q;
    if (has_one) {
        dist[1] = 1;
    }
    for (int x : distinct_elements) {
        dist[x] = 1;
        q.push(x);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int x : distinct_elements) {
            long long v_long = (long long)u * x;
            if (v_long > n) break;
            int v = (int)v_long;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << endl;
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
