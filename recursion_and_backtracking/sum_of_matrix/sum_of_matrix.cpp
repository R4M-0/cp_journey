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

void sum_of_matrix(vector<vll>& a, vector<vll>& b,
                   vector<vll>& s,
                   ll i, ll j, ll r, ll c) {

    if (i == r) return;

    if (j == c) {
        sum_of_matrix(a, b, s, i + 1, 0, r, c);
        return;
    }

    s[i][j] = a[i][j] + b[i][j];

    sum_of_matrix(a, b, s, i, j + 1, r, c);
}

void solve() {
    ll r, c;
    cin >> r >> c;

    vector<vll> a(r, vll(c));
    vector<vll> b(r, vll(c));
    vector<vll> s(r, vll(c));

    for (ll i = 0; i < r; i++)
        for (ll j = 0; j < c; j++)
            cin >> a[i][j];

    for (ll i = 0; i < r; i++)
        for (ll j = 0; j < c; j++)
            cin >> b[i][j];

    sum_of_matrix(a, b, s, 0, 0, r, c);

    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
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
