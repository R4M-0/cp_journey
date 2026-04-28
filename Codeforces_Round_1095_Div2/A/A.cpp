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

const int MOD = 676767677;
const ll INF = 1e18;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)(v).size()

#define pb push_back
#define fi first
#define se second
#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define f(i, b) for (ll i = 0LL; i < (ll)(b); ++i)
#define fa(i, a, b) for (ll i = (a); i < (ll)(b); ++i)
#define rf(i, a, b) for (ll i = (a); i >= (ll)(b); --i)
#define each(a, x) for (auto &a : x)

template <typename T> istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x : v) in >> x;
    return in;
}

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        out << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    return out;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}
ll modpow(ll a, ll e, ll mod = MOD) {
    ll r = 1;
    while (e) {
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}
//ay 1 najmou nzidouh ballouchi
//ken fama 1 wahdou nzidou 1 lel sum
//snn sum mtaa ay adad mch 1
void solve() {
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    ll last_non_one = -1;
    ll sum_non_one = 0;
    for(ll i=0; i< n ; i++) {
        if (a[i] != 1) {
            last_non_one = i;
            sum_non_one += a[i];
        }
    }
    if (last_non_one == -1) {
        cout << 1 << endl;
        return;
    }
    bool trailing_ones = false;
    for(ll i=(last_non_one + 1); i< n; i++) {
        if (a[i] == 1) { trailing_ones = true; break; }
    }

    cout << (sum_non_one + (trailing_ones ? 1 : 0)) % MOD << endl;
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
