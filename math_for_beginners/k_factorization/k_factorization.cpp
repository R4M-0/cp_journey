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
    ll n, k;
    cin >> n >> k;

    ll n1 = n;
    vector<ll> v;

    for (ll i = 2; i * i <= n1; i++) {
        while (n1 % i == 0) {
            v.push_back(i);
            n1 /= i;
        }
    }
    if (n1 > 1) v.push_back(n1);

    if ((ll)v.size() < k) {
        cout << -1 << endl;
        return;
    }

    ll last = 1;
    for (ll i = 0; i < k - 1; i++) {
        cout << v[i] << " ";
    }

    for (ll i = k - 1; i < (ll)v.size(); i++) {
        last *= v[i];
    }

    cout << last << endl;
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
