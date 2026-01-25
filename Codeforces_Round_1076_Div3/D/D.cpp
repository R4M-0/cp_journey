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
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vll b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(rall(a));
    ll max_score = 0;
    ll swords_needed = 0;
    for (int i = 0; i < n; i++) {
        swords_needed += b[i];
        if (swords_needed > n) break;
        ll current_x = a[swords_needed - 1];
        ll current_score = current_x * (i + 1);
        max_score = max(max_score, current_score);
    }
    cout << max_score << endl;
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
