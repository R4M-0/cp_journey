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

    if (n % 2 != 0 || n < 4) {
        cout << -1 << endl;
        return;
    }

    ll mn = -1, mx = -1;

    for (ll six = n / 6; six >= 0; six--) {
        ll rem = n - six * 6;
        if (rem % 4 == 0) {
            mn = six + rem / 4;
            break;
        }
    }

    for (ll four = n / 4; four >= 0; four--) {
        ll rem = n - four * 4;
        if (rem % 6 == 0) {
            mx = four + rem / 6;
            break;
        }
    }

    if (mn == -1 || mx == -1) {
        cout << -1 << endl;
    } else {
        cout << mn << " " << mx << endl;
    }
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
