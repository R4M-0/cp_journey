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
        vector<int> a(n), b(n), c(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        for (int &x : c) cin >> x;
        vector<int> D(n, INT_MIN), E(n, INT_MIN);
        for (int d = 0; d < n; d++) {
            int mx = INT_MIN;
            for (int x = 0; x < n; x++) {
                mx = max(mx, a[x] - b[(x + d) % n]);
            }
            D[d] = mx;
        }
        for (int d = 0; d < n; d++) {
            int mx = INT_MIN;
            for (int x = 0; x < n; x++) {
                mx = max(mx, b[x] - c[(x + d) % n]);
            }
            E[d] = mx;
        }
        ll cntAB = 0, cntBC = 0;
        for (int d = 0; d < n; d++) {
            if (D[d] < 0) cntAB++;
            if (E[d] < 0) cntBC++;
        }

        cout << 1LL * n * cntAB * cntBC << endl;
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
