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
    for (int i = 0; i < (int)v.size(); ++i) {
        out << v[i] << (i == (int)v.size() - 1 ? "" : " ");
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

void solve() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    cin >> a;
    unordered_set<ll> s(all(a));
    ll sz = (ll)s.size();
    unordered_set<ll> e;
    for (ll x : s) {
        if (k / x > sz) continue;
        bool ok = true;
        for (ll m = x; m <= k; m += x) {
            if (!s.count(m)) { ok = false; break; }
        }
        if (ok) e.insert(x);
    }

    unordered_set<ll> non_min;
    for (ll x : e) {
        for (ll m = 2 * x; m <= k; m += x) {
            if (e.count(m)) non_min.insert(m);
        }
    }

    vll m;
    for (ll x : e) {
        if (!non_min.count(x)) m.push_back(x);
    }
    unordered_set<ll> covered;
    for (ll m1 : m) {
        for (ll mult = m1; mult <= k; mult += m1) {
            covered.insert(mult);
        }
    }

    for (ll ai : a) {
        if (!covered.count(ai)) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << m.size() << "\n";
    cout << m << "\n";
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
