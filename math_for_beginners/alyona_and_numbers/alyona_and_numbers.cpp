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
    ll n, m;
    cin >> n >> m;

    ll cntN[5] = {0}, cntM[5] = {0};

    for (int r = 0; r < 5; r++) {
        cntN[r] = n / 5;
        if (r != 0 && r <= n % 5) cntN[r]++;
    }

    for (int r = 0; r < 5; r++) {
        cntM[r] = m / 5;
        if (r != 0 && r <= m % 5) cntM[r]++;
    }

    ll ans = 0;
    ans += cntN[0] * cntM[0];
    ans += cntN[1] * cntM[4];
    ans += cntN[2] * cntM[3];
    ans += cntN[3] * cntM[2];
    ans += cntN[4] * cntM[1];

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
