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
    ll n; 
    cin >> n;
    vll a(n);
    for (ll &x : a) cin >> x;

    auto count_inv = [&](const vll &b) {
        ll inv = 0, ones = 0;
        for (ll x : b) {
            if (x == 1) ones++;
            else inv += ones;
        }
        return inv;
    };

    ll ans = count_inv(a);
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            a[i] = 1;
            ans = max(ans, count_inv(a));
            a[i] = 0;
            break;
        }
    }
    for (ll i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            a[i] = 0;
            ans = max(ans, count_inv(a));
            a[i] = 1;
            break;
        }
    }

    cout << ans << '\n';
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
