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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    vector<vector<int>> subsets;

    for (int mask = 1; mask < (1 << n); mask++){
        vector<int> curr_subset;

        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                curr_subset.pb(v[i]);

        subsets.pb(curr_subset);
    }
    sort(all(subsets));

    int m = subsets.size();
    vector pref(n, vector<int>(m + 2, 0));

    int q;
    cin >> q;

    auto get_index = [&](int x){
	for (int i = 0; i < n; i++)
            if (v[i] == x)
                return i;
    };

    while (q--){
        int l, r, val;
        cin >> l >> r >> val;

        l--, r--;

        int indx_ofval = get_index(val);
        pref[indx_ofval][l] += 1;
        pref[indx_ofval][r + 1] -= 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            pref[i][j] += pref[i][j - 1];

    vector<int> ans(m, 1);

    for (int i = 0; i < m; i++){
        vector<int> occ(n);
        for (auto x : subsets[i])
            occ[get_index(x)]++;

        for (int j = 0; j < n; j++)
            occ[j] += pref[j][i];

        for (int j = 0; j < n; j++){
            ans[i] *= (occ[j] % 2 == 1 ? v[j] : 1);
            ans[i] %= MOD;
        }
    }

    for (auto x : ans) cout << x << " ";
    cout << endl;
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
