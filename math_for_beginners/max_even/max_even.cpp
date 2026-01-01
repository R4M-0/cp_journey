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

    vll v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    vll even, odd;

    for (ll x : v) {
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    sort(rall(even));
    sort(rall(odd));

    ll ans = -1;

    if (even.size() >= 2) {
        ans = max(ans, even[0] + even[1]);
    }
    if (odd.size() >= 2) {
        ans = max(ans, odd[0] + odd[1]);
    }

    cout << ans << endl;
}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << '\n';
    }
    return 0;
}
