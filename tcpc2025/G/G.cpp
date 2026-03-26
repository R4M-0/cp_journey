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
    for (auto &x : v)
        in >> x;
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
        if (e & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> cols(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> cols[j][i];

    for (int j = 0; j < m; j++)
        sort(cols[j].begin(), cols[j].end());

    vector<int> current(cols[0]); 
    for (int j = 1; j < m; j++) {
        vector<int> next_col = cols[j]; 
        vector<int> survived;
        vector<bool> used(n, false);
        int ptr = 0;
        vector<int> next_survived;

        for (int i = 0; i < (int)current.size(); i++) {
            while (ptr < (int)next_col.size() && next_col[ptr] < current[i])
                ptr++;
            if (ptr < (int)next_col.size()) {
                next_survived.push_back(next_col[ptr]);
                ptr++;
            }
        }

        current = next_survived;
    }

    cout << (int)current.size() << "\n";
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
