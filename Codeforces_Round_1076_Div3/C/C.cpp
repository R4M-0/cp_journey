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
    int n, q;
    cin >> n >> q;
    vll a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vll c(n);
    for (int i = 0; i < n; i++) {
        c[i] = max(a[i], b[i]);
    }

    vll suf(n);
    suf[n - 1] = c[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(c[i], suf[i + 1]);
    }

    vll pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + suf[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; 
        r--; 
        ll range_sum = pref[r + 1] - pref[l];
        cout << range_sum << (i == q - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
