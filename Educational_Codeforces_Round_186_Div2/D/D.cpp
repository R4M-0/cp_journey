#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MA9ROUNA_KADHEBA                       \
    ios_base::sync_with_stdio(false);          \
    cin.tie(NULL);                             \
    cout.tie(NULL);

const int MOD = 998244353; 

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

ll fact[100];
ll invFact[100];

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < 100; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modpow(fact[i], MOD - 2, MOD);
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll S = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        S += a[i];
    }

    ll k = S / n;
    ll r = S % n;

    int cnt1 = 0; 
    int cnt2 = 0; 
    int cnt3 = 0; 

    for (int i = 1; i <= n; i++) {
        if (a[i] <= k) {
            cnt1++;
        } else if (a[i] == k + 1) {
            cnt2++;
        } else {
            cnt3++;
        }
    }

    if (cnt3 > 0) {
        cout << 0 << '\n';
        return;
    }

    if (cnt2 > r) {
        cout << 0 << '\n';
        return;
    }

    ll ways = nCr(cnt1, r - cnt2);
    ll permA = fact[r];
    ll permB = fact[n - r];

    ll ans = ways * permA % MOD;
    ans = ans * permB % MOD;

    cout << ans << '\n';
}

int main() {
    MA9ROUNA_KADHEBA
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
