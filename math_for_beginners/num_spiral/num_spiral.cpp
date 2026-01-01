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
    ll y, x;
    cin >> y >> x;

    if (y == 1 && x == 1) { 
        cout << 1 << endl;
        return;
    }

    ll ans;

    if (x >= y) {
        if (x % 2 == 1) {
            ans = x * x;         
            while (--y) {         
                ans--;
            }
        } else {
            ans = (x - 1) * (x - 1) + 1;  
            while (--y) {                 
                ans++;
            }
        }
    }
    else {  
        if (y % 2 == 0) {
            ans = y * y;         
            while (--x) {         
                ans--;
            }
        } else {
            ans = (y - 1) * (y - 1) + 1;  
            while (--x) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
