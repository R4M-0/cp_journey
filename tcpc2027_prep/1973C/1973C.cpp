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

void solve() {
	int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        vector<int> q(n);
        int nid = find(p.begin(), p.end(), n) - p.begin();
        if (!(nid & 1)){
            vector<pair<int, int> > v;
            for (int i = 1; i < n; i += 2) v.push_back({ p[i], i });
            v.push_back({ p[0], 0 });
            for (int i = 2; i < n; i += 2) v.push_back({ p[i], i });
            sort(v.begin(), v.begin() + (n / 2), greater<pair<int, int> >());
            sort(v.begin() + (n / 2) + 1, v.begin() + n, greater<pair<int, int> >());
            for (int i = 0; i < n; i++) q[v[i].second] = i + 1;
        }
        else 
        {
            vector<pair<int, int> > v;
            for (int i = 0; i < n; i += 2) v.push_back({ p[i], i });
            v.push_back({ p[n - 1], n - 1 });
            for (int i = 1; i < n - 1; i += 2) v.push_back({ p[i], i });
            sort(v.begin(), v.begin() + (n / 2), greater<pair<int, int> >());
            sort(v.begin() + (n / 2) + 1, v.begin() + n, greater<pair<int, int> >());
            for (int i = 0; i < n; i++) q[v[i].second] = i + 1;
        }
        for (int i = 0; i < n; i++) cout << q[i] << " \n"[i == n - 1];
}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        //cout << '\n';
    }
    return 0;
}
