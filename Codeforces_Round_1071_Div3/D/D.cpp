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

int popcount(int x) {
    return __builtin_popcount(x);
}
bool isPowerOf2(long long x) {
    return x > 0 && (x & (x - 1)) == 0;
}
void solve() {
    ll n;
    cin >> n;
    ll mask = (1LL << n) - 1;
    vll p;
    p.push_back(mask);

    vector<bool> u(mask + 1, 0);
    u[mask] = 1;

    for (ll b = n - 1; b >= 0; --b) {
        ll next_mask = mask ^ (1 << b);
        vll v;
        ll not_needed = n - 1 - b;
        for (ll i = 0; i < (1LL << not_needed); i++) {
            ll x = next_mask;
            for (ll j = 0; j < not_needed; j++) {
                if ((i >> j) & 1) {
                    x |= (1 << (b + 1 + j));
                }
            }
            if (!u[x]) {
                u[x] = 1;
                v.push_back(x);
            }
        }
        sort(all(v));
        for (ll x : v) {
            p.push_back(x);
        }
        mask = next_mask;
    }
    for (ll x : p) {
        cout << x << " ";
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

